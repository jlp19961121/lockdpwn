#include "../inc/VelocityCtrlThread.h"

VelocityCtrlThread::VelocityCtrlThread(int argc, char** argv, Ui::MainWindow* ui)
    :m_bThreadStop(false)
    , init_argc(argc), init_argv(argv), _ui(ui)
{
  ros::init(init_argc, init_argv, "VelocityCtrlThread");
  ros::NodeHandle n;

  m_currentVel = 0;
  m_targetVel = 0;
  m_bVelTopicUpdated = false;

  m_auto_brake = 18.0;
  //	m_accel_max = 30.0;
  //	m_accel_min = 25.0;
  m_accel_max = 25.0;
  m_accel_min = 5.0;

  m_brake_max = 35.0;	//JW 07.20.
  //m_brake_min = 0.0;	//orig
  m_brake_min = 5.0;	//JW 07.20.
  m_brake_idle = 0.0;
  //m_brakingCtrlVal = 5.0*0.278;	//orig
  m_brakingCtrlVal = 6.1*0.278;	//JW 07.20.
	

  //m_limit_vel_low_error = 1.0;
  //m_limit_vel_up_error = 5.0;

  m_P_brake = 0.0;	m_I_brake = 0.0;
  m_P_accel = 0.0;	m_I_accel = 0.0;
  m_accel_pgain = 3.9;	m_accel_igain = 0.1;
  m_brake_pgain = -9.0;	m_brake_igain = -0.5;


  // ed: 가제보용 코드 추가
  possub_gazebo = n.subscribe("LocalizationData_gazebo", 100, &VelocityCtrlThread::callback_LocalizationData_gazebo, this);
  drcsub_gazebo = n.subscribe("ControlData_gazebo", 10, &VelocityCtrlThread::callback_ControlData_gazebo, this);

  msgpub = n.advertise<std_msgs::Float32MultiArray>("VelocityCtrlData", 1);
  msgpub_vel_err = n.advertise<std_msgs::Float32MultiArray>("Vel_err", 1);

  _ui->label_tarvel->setText(QString::number(0));
  _ui->label_curvel->setText(QString::number(0));
}

void VelocityCtrlThread::callback_LocalizationData_gazebo(const std_msgs::Float32MultiArray::ConstPtr& msg){
  if(!m_bVelTopicUpdated)  {
    m_currentVel = msg->data.at(3);
    m_bVelTopicUpdated = true;
  }
}

void VelocityCtrlThread::callback_ControlData_gazebo(const std_msgs::Float32MultiArray::ConstPtr& msg){
  {
    QMutexLocker locker(&m_mutex);

    // ed: controller 창에서 속도 start버튼 옆에 체크박스를 선택한 경우
    if( _ui->checkBox_Vel->isChecked() ) {
      TargetVelUpdate(msg->data.at(6));
      //printf("ControlData(6) is : %lf\n", msg->data.at(6));
    }
    else {
      TargetVelUpdate(0);
    }
  }
}

void VelocityCtrlThread::TargetVelUpdate(float targetVel){
  m_targetVel = targetVel;
  //printf("input_brk : %lf\n", m_targetVel);
}


void VelocityCtrlThread::TargetVelUpdate(){
  // ed: 아래 주석처리되어있던 코드를 해제했다
  m_currentVel = rand()%20;
  m_targetVel = rand()%20;
}


void VelocityCtrlThread::stop(){
  //qDebug()<<"Thread::stop called from main thread:"<<currentThreadId();
  QMutexLocker locker(&m_mutex);
  m_bThreadStop = true;
  _ui->label_tarvel->setText("---");
  _ui->label_curvel->setText("---");
}

void VelocityCtrlThread::run() { //Check Button
  int cnt = 0;
  ros::Rate loop_rate(10);	//100ms

  while(1) {
    {
      QMutexLocker locker(&m_mutex);
      if(m_bThreadStop) break;

      if(m_bVelTopicUpdated) { //Sub
        cnt++;
        printf("cnt : %d\n", cnt);
        if( cnt == 50 )  {
          _ui->label_tarvel->setText(QString::number(m_targetVel));
          _ui->label_curvel->setText(QString::number(m_currentVel));
          cnt =0;
        }
        // ed: 여기 포함해서 많은 부분에 3.6이 곱해져있었는데 m/s로 나타내기 위해 3.6을 삭제했다
        printf("tar : %lf m/s curr : %lf m/s\n",m_targetVel, m_currentVel);

        float vel_error = m_targetVel - m_currentVel;

        {
          printf("vel_err : %lf\n",vel_error);
          if((m_targetVel >= 0 && m_targetVel <= m_brakingCtrlVal) || (m_currentVel >= 0 && m_currentVel <= 2.0 *0.278))
            // 0 ~ 6.1km/h	////////////////
            // velocity control using brake pedal
          {
            //m_brake = m_brake_idle + m_brake_pgain * 1.0 * vel_error;	//integral	(gain : -0.1) -> +	//JW 07.20.
            //printf("output_brk : %lf\n",m_brake);
            //if(m_brake <= m_brake_min)	//0
            //	m_brake = m_brake_min;
            //else if(m_brake >= m_brake_max)	//18
            //	m_brake = m_brake_max;
						
            ///orig

            m_accel = 0.0;
							
            m_P_brake = m_brake_pgain * vel_error;
            m_I_brake = m_I_brake + m_brake_igain * vel_error;	//integral	(gain : -0.1) -> +	//orig
            m_brake = m_brake_min + m_P_brake + m_I_brake;

            printf("P : %lf",m_P_brake);
            printf(",   I : %lf\n",m_I_brake);

            if(m_I_brake <= 0)
              m_I_brake = 0;
            else if(m_I_brake >= m_brake_max)
              m_I_brake = m_brake_max;

            if(m_brake <= m_brake_min)	//7
              m_brake = m_brake_min;
            else if(m_brake >= m_brake_max)	//19
              m_brake = m_brake_max;

            ///orig
            printf("only break : %lf\n\n",m_brake);
          }
          else	//6.1km/h up
            // velocity control using acc
          {
            //printf("else acc");

            if(vel_error > 0.0 )	//acc
            {
              //if(abs(vel_error) > 1.0)
              //{
              m_P_accel = m_accel_pgain * vel_error;
              m_I_accel = m_I_accel + m_accel_igain * vel_error;
              m_accel = m_accel_min + m_P_accel + m_I_accel;

              printf("P : %lf",m_P_accel);
              printf(",   I : %lf\n",m_I_accel);

              if(m_I_accel <= 0)
                m_I_accel = 0;
              else if(m_I_accel >= m_accel_max)
                m_I_accel = m_accel_max;

              if(m_accel >= m_accel_max)	//15%
                m_accel = m_accel_max;
              else if(m_accel <= m_accel_min)	//0%
                m_accel = m_accel_min;

              m_brake = 0.0;	m_I_brake -= 0.9;
              if(m_I_brake < 0)
                m_I_brake = 0;
              printf("vel up acc : %lf\n\n",m_accel);
              //}
            }
            else	//brake
            {
	
              m_accel = m_accel_min;//JW
							
              m_P_brake = m_brake_pgain * vel_error;
              m_I_brake = m_I_brake + m_brake_igain*(1.5) * vel_error;	//integral	(gain : -0.1) -> +	//orig
              m_brake = m_brake_min + m_P_brake + m_I_brake;

              printf("P : %lf",m_P_brake);
              printf(",   I : %lf\n",m_I_brake);

              if(m_I_brake <= 0)
                m_I_brake = 0;
              else if(m_I_brake >= m_brake_max)
                m_I_brake = m_brake_max;

              if(m_brake <= m_brake_min)
                m_brake = m_brake_min;
              else if(m_brake >= m_brake_max)
                m_brake = m_brake_max;
								
              m_I_accel = 0.0;
              printf("vel down break : %lf\n\n",m_brake);
            }
          }
        }
        //m_accel=0;//JW
        // publish msg
        std_msgs::Float32MultiArray msg;
        msg.data.push_back(m_accel);
        msg.data.push_back(m_brake);
        //MotionPlanner::VelocityCtrlData data;
        //data.acc = m_accel;
        //data.brk = m_brake;
        msgpub.publish(msg);


        // publish msg vel err
        std_msgs::Float32MultiArray msg_err;
        msg_err.data.push_back(m_targetVel);
        msg_err.data.push_back(m_currentVel);
        msg_err.data.push_back(vel_error);
        msg_err.data.push_back(m_accel);
        msg_err.data.push_back(m_brake);
        msgpub_vel_err.publish(msg_err);


        m_bVelTopicUpdated = false;
      }
    }
    ros::spinOnce();
    loop_rate.sleep();

  }
}

