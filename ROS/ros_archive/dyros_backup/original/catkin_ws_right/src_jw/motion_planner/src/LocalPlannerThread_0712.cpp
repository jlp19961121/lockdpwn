#include "../inc/LocalPlannerThread.h"
#include <QPointF>
#include <QDebug>
#include "../inc/CatmullRomSpline.h"

// From Localization Module
void LocalPlannerThread::SubTopicProcess1(const std_msgs::Float32MultiArray::ConstPtr& msg)
{
        m_pos[0] = msg->data.at(0);
        m_pos[1] = msg->data.at(1);
        m_pos[2] = msg->data.at(2);
        m_vel = msg->data.at(3); // m/s

        Compute();
}

void LocalPlannerThread::SubTopicProcess2(const nav_msgs::Path::ConstPtr& msg)
{
	// Insertion Global Path Data to Vector Struct
        vector<Vector2d> nodeVec;
        for( int i=0; i<msg->poses.size(); i++)
        {
            nodeVec.push_back(Vector2d(msg->poses[i].pose.position.x, msg->poses[i].pose.position.y));
        }

	// Generation of Interpolation Curve
        CatmullRomSpline spline;
        vector<Vector2d> curvePath = spline.PathToCurve( nodeVec, 1, 1000);
        m_LocalSplinePath = curvePath;
       
	// Publish for Visualization
        publish_local_path(m_LocalSplinePath);
}

void LocalPlannerThread::publish_local_path(vector<Vector2d> path)
{
    nav_msgs::Path msg;
    std::vector<geometry_msgs::PoseStamped> waypoints;
    msg.header.frame_id = "/camera_init";
    msg.header.stamp = ros::Time::now();


    //////////////////////////////////////////
    // POSE STAMPED
    for(int i=0; i<path.size(); i++)
    {
        geometry_msgs::PoseStamped waypt;
        waypt.header.frame_id = "/camera_init";
        waypt.header.stamp = ros::Time::now();


        waypt.pose.position.x = path[i][0];
        waypt.pose.position.y = path[i][1];
        waypt.pose.position.z = 0;
        waypoints.push_back(waypt);

    }

    msg.poses.resize(waypoints.size());

    // Extract the plan in world coordinates, we assume the path is all in the same frame
    for(unsigned int i=0; i < waypoints.size(); i++)
    {
        msg.poses[i] = waypoints[i];
    }
    msgpub.publish(msg);

}

void LocalPlannerThread::GetLookAheadPt_JW(double &lookAheadDist,double& x, double& y, double &resdist)
{
	

double delta_LookAhead = 0.0;
double m_len_c2r = 1.10;



    if (m_LocalSplinePath.size() > 1)
    {
	//JW 16.06.24.test1
	m_pos[0] += m_len_c2r*cos(m_pos[2]);
	m_pos[1] += m_len_c2r*sin(m_pos[2]);
	//JW 16.06.24.test1

        double minDist = 99999;
        int cIndex = -1;
        int lookIndex = -1;
        for(int i = 0; i<m_LocalSplinePath.size(); i++)
        {
            double x2 = m_LocalSplinePath[i][0] - m_pos[0];
            x2 *= x2;
            double y2 = m_LocalSplinePath[i][1] - m_pos[1];
            y2 *= y2;
            double dist = sqrt(x2+y2);//distŽÂ 
            if ( dist < minDist )
            {
                minDist = dist;
                cIndex = i;
            }
        }

	//JW 16.06.24.test1
	//m_LookAhead_X = m_LocalSplinePath[cIndex][0];
	//m_LookAhead_Y = m_LocalSplinePath[cIndex][1];

	m_th_Err = abs(m_pos[2] - atan2((m_LookAhead_Y - m_pos[1]), (m_LookAhead_X - m_pos[0])));
	double turning_rad = abs(M_PI - abs(atan2(m_LookAhead_Y - m_LookAhead_Y_pre, m_LookAhead_X - m_LookAhead_X_pre))) / 3.14;
	turning_rad = turning_rad*turning_rad;

	m_LookAhead_X_pre = m_LookAhead_X;
	m_LookAhead_Y_pre = m_LookAhead_Y;

	m_dist_Err = sqrt((m_LookAhead_X - m_pos[0])*(m_LookAhead_X - m_pos[0]) 
				+ (m_LookAhead_Y - m_pos[1])*(m_LookAhead_Y - m_pos[1]));
	
	if (m_th_Err < 0.01)	m_th_Err = 0.01;
		delta_LookAhead = (double)(1 / m_th_Err) + 0.1*turning_rad*m_th_Err*m_dist_Err;

	lookAheadDist = delta_LookAhead + 6;
	//JW 16.06.24.test1
	
	m_err.data.push_back(m_th_Err);
	m_err.data.push_back(m_dist_Err);
	m_err.data.push_back(lookAheadDist);
	msgpub_err.publish(m_err);

	double dist = 0;
        int lookAheadIndex = -1;
        for( int i=cIndex; i<m_LocalSplinePath.size()-1; i++ )
        {
            double x2 = m_LocalSplinePath[i][0] - m_LocalSplinePath[i+1][0];
            x2 *= x2;
            double y2 = m_LocalSplinePath[i][1] - m_LocalSplinePath[i+1][1];
            y2 *= y2;
            dist += sqrt(x2+y2);

            if( lookAheadDist <= dist)
            {
                lookAheadIndex = i;
                x = m_LookAhead_X = m_LocalSplinePath[i+1][0];
                y = m_LookAhead_Y = m_LocalSplinePath[i+1][1];
		
                resdist = lookAheadDist;
                break;
            }
        }


        if( lookAheadIndex == -1 )
        {
            x = m_LocalSplinePath[m_LocalSplinePath.size()-1][0];
            y = m_LocalSplinePath[m_LocalSplinePath.size()-1][1];
            resdist = -1;
        }

    }
	

}

void LocalPlannerThread::GetLookAheadPt(double lookAheadDist,double& x, double& y, double &resdist)
{
    if (m_LocalSplinePath.size() > 1)
    {
        double minDist = 99999;
        int cIndex = -1;
        int lookIndex = -1;
        for(int i = 0; i<m_LocalSplinePath.size(); i++)
        {
            double x2 = m_LocalSplinePath[i][0] - m_pos[0];
            x2 *= x2;
            double y2 = m_LocalSplinePath[i][1] - m_pos[1];
            y2 *= y2;
            double dist = sqrt(x2+y2);//distŽÂ 
            if ( dist < minDist )
            {
                minDist = dist;
                cIndex = i;
            }
        }
	

	double dist = 0;
        int lookAheadIndex = -1;
        for( int i=cIndex; i<m_LocalSplinePath.size()-1; i++ )
        {
            double x2 = m_LocalSplinePath[i][0] - m_LocalSplinePath[i+1][0];
            x2 *= x2;
            double y2 = m_LocalSplinePath[i][1] - m_LocalSplinePath[i+1][1];
            y2 *= y2;
            dist += sqrt(x2+y2);

            if( lookAheadDist <= dist)
            {
                lookAheadIndex = i;
                x = m_LocalSplinePath[i+1][0];
                y = m_LocalSplinePath[i+1][1];
                resdist = dist;
                break;
            }
        }

        if( lookAheadIndex == -1 )
        {
            x = m_LocalSplinePath[m_LocalSplinePath.size()-1][0];
            y = m_LocalSplinePath[m_LocalSplinePath.size()-1][1];
            resdist = -1;
        }

    }
	

}

LocalPlannerThread::LocalPlannerThread(int argc, char** argv)
    :m_bThreadStop(false),init_argc(argc), init_argv(argv)
{
    ros::init(init_argc, init_argv, "LocalPlannerThread");
    ros::NodeHandle n;
    
    //JW 16.07.07//jw 16.07.08
    //my_pose
    m_CarPos.header.frame_id =  m_line_strip.header.frame_id = "/camera_init";
    m_CarPos.ns = m_line_strip.ns = "RegionOfInterest";
    m_CarPos.id = 0;
    //m_line_strip.id = 1;

    m_CarPos.type= visualization_msgs::Marker::SPHERE;
    //m_line_strip.type = visualization_msgs::Marker::LINE_STRIP;

    m_CarPos.action = m_line_strip.action = visualization_msgs::Marker::ADD;
    m_CarPos.pose.position.z = 0;

    m_CarPos.scale.x = 1.0;
    m_CarPos.scale.y = 1.0;
    m_CarPos.scale.z = 1.0;
    m_CarPos.color.a = 1.0;
    m_CarPos.color.r = 1.0f;
    m_CarPos.color.g = 0.0f;
    m_CarPos.color.b = 0.0f;

    m_line_strip.pose.position.z = 0.1;
    m_line_strip.color.r = 1.0;
    m_line_strip.color.a = 1.0; 
    //JW 16.07.07//jw 16.07.08
	
    //LookAhead
    m_model_jw.header.frame_id= "/camera_init";
    m_model_jw.ns = "RegionOfInterest";
    m_model_jw.id = 0;

    m_model_jw.type= visualization_msgs::Marker::SPHERE;
    m_model_jw.action = visualization_msgs::Marker::ADD;
    m_model_jw.pose.position.z = 0;

    m_model_jw.scale.x = 1.0;
    m_model_jw.scale.y = 1.0;
    m_model_jw.scale.z = 1.0;
    m_model_jw.color.a = 1.0;
    m_model_jw.color.r = 0.0f;
    m_model_jw.color.g = 1.0f;
    m_model_jw.color.b = 0.0f;

    //jw 16.07.08
    m_model_orig.header.frame_id= "/camera_init";
    m_model_orig.ns = "RegionOfInterest";
    m_model_orig.id = 0;

    m_model_orig.type= visualization_msgs::Marker::SPHERE;
    m_model_orig.action = visualization_msgs::Marker::ADD;
    m_model_orig.pose.position.z = 0;

    m_model_orig.scale.x = 1.0;
    m_model_orig.scale.y = 1.0;
    m_model_orig.scale.z = 1.0;
    m_model_orig.color.a = 1.0;
    m_model_orig.color.r = 0.0f;
    m_model_orig.color.g = 0.0f;
    m_model_orig.color.b = 1.0f;
    //jw 16.07.08

	m_LookAhead_X_pre = 0.0;//JW 16.06.24.test1
	m_LookAhead_Y_pre = 0.0;//JW 16.06.24.test1

   m_CarPos.header.frame_id =  m_line_strip.header.frame_id = "/camera_init";
    m_CarPos.ns = m_line_strip.ns = "RegionOfInterest";
    m_CarPos.id = 0;
    //m_line_strip.id = 1;

    m_CarPos.type= visualization_msgs::Marker::SPHERE;
    //m_line_strip.type = visualization_msgs::Marker::LINE_STRIP;

    m_CarPos.action = m_line_strip.action = visualization_msgs::Marker::ADD;
    m_CarPos.pose.position.z = 0;

    m_CarPos.scale.x = 1.0;
    m_CarPos.scale.y = 1.0;
    m_CarPos.scale.z = 1.0;
    m_CarPos.color.a = 1.0;
    m_CarPos.color.r = 1.0f;
    m_CarPos.color.g = 0.0f;
    m_CarPos.color.b = 0.0f;

  

    msgpub = n.advertise<nav_msgs::Path>("LocalPathData", 10);
    msgpub2 = n.advertise<visualization_msgs::Marker>("LookAheadPos", 10);//real use data
    msgpub_Look_orig = n.advertise<visualization_msgs::Marker>("LookAheadPos_oirg", 10);//just visualization
    msgpub_car = n.advertise<visualization_msgs::Marker>("Car_Pos", 10);//car_pos_ visualization
    msgpub_err = n.advertise<std_msgs::Float32MultiArray>("err_", 10);//err_ 
    msgpub3 = n.advertise<std_msgs::Float32MultiArray>("ControlData", 10);


    possub = n.subscribe("LocalizationData", 10, &LocalPlannerThread::SubTopicProcess1, this);
    possub2 = n.subscribe("RNDFPathData", 10, &LocalPlannerThread::SubTopicProcess2, this);
    
}

LocalPlannerThread::~LocalPlannerThread()
{

}

void LocalPlannerThread::stop()
{
    qDebug()<<"Thread::stop called from main thread:"<<currentThreadId();
    QMutexLocker locker(&m_mutex);
    m_bThreadStop = true;
}

void LocalPlannerThread::PubMsg()
{
   publish_local_path(m_LocalSplinePath);
}

////JW 16.07.11.test1
void LocalPlannerThread::Pub_JWPathMsg()
{
	int count = 0;
	double X,Y;
	string garbage_X,garbage_Y;

	ifstream fin_X, fin_Y;
	vector<Vector2d> nodeVec;

	fin_X.open("/home/dyros-vehicle/00_DATA/bag/output_X.txt");
	fin_Y.open("/home/dyros-vehicle/00_DATA/bag/output_Y.txt");

	while(fin_X != NULL)
	//for(int i = 0 ; i < 30 ; i++)
	{

		fin_X >> X >> garbage_X;
		fin_Y >> Y >> garbage_Y;
		
		nodeVec.push_back(Vector2d(X, Y));
		printf("[%d] X : %lf,  Y : %lf\n",count++,X,Y);
	}

// Generation of Interpolation Curve
        CatmullRomSpline spline;
        vector<Vector2d> curvePath = spline.PathToCurve( nodeVec, 1, 1000);
        m_LocalSplinePath = curvePath;
       
	// Publish for Visualization
        publish_local_path(m_LocalSplinePath);
}
////JW 16.07.11.test1

void LocalPlannerThread::Compute()
{
        //printf("Car_x : %lf, Car_y : %lf\n",m_pos[0],m_pos[1]);

  	double vel_orig, delta_L, x, y, resdist;
	double x_orig, y_orig;
//JW 16.06.24.orig
	if( m_vel > 8.0 * 0.278 )
	{
		//printf("%lf\n",m_vel);
		GetLookAheadPt(4.0*m_vel, x, y, resdist);//JW 16.07.14.test1
		//GetLookAheadPt(0.0, x, y, resdist);//JW 16.07.14.test1
		vel_orig = 4.0*m_vel;
	}	
	else
	{
		GetLookAheadPt(6.0, x, y, resdist);//JW 16.07.14.test1
	//	GetLookAheadPt(0.0, x, y, resdist);	//JW 16.07.14.test1
		vel_orig = 6.0;
	}
	x_orig = x;
	y_orig = y;
//	printf("Orgi.. m_vel : %lf, x : %lf, y : %lf, dist : %lf\n",4.0*m_vel,x_orig,y_orig,resdist);//JW 16.07.14.test1
	x = y = resdist = 0;
//JW 16.06.24.orig

//JW 16.06.24.test1
	GetLookAheadPt_JW(delta_L, x, y, resdist);	//JW 16.07.14.test1
	printf("Orgi.. m_vel : %lf, x : %lf, y : %lf, dist : %lf\nJWJW.. delta : %lf, x : %lf, y : %lf, dist : %lf\n\n",vel_orig,x_orig,y_orig,resdist,delta_L,x,y,resdist);

	//////////////////////////////////////////////////////////////
	// ControlData Message 
	m_msg.data.clear();
	m_msg.data.push_back(x);
	m_msg.data.push_back(y);
	m_msg.data.push_back(resdist);
	m_msg.data.push_back(m_pos[0]);
	m_msg.data.push_back(m_pos[1]);
	m_msg.data.push_back(m_pos[2]);

	if( resdist == -1)
	{
		m_msg.data.push_back(0.0*0.278);
	}
	else
	{	
		m_msg.data.push_back(4.8*0.278);
	}
	msgpub3.publish(m_msg);
	
        //JW 16.07.07
	// My_pos Message Red
	m_CarPos.header.stamp = ros::Time::now();
	m_CarPos.pose.position.x = m_pos[0];
	m_CarPos.pose.position.y = m_pos[1];
	msgpub_car.publish(m_CarPos);
	
	//JW 16.07.08 Trajectory Red 
	m_line_strip.header.stamp = ros::Time::now();
	m_line_strip.points.push_back(m_CarPos.pose.position);
	msgpub_car.publish(m_line_strip);
        //JW 16.07.08

	// Look Ahead Message  _JW Green
	m_model_jw.header.stamp = ros::Time::now();
	m_model_jw.pose.position.x = x;
	m_model_jw.pose.position.y = y;
	msgpub2.publish(m_model_jw);

	//JW 16.07.08
	// Look Ahead Message _ORIG Blue
	m_model_orig.header.stamp = ros::Time::now();
	m_model_orig.pose.position.x = x_orig;
	m_model_orig.pose.position.y = y_orig;
	msgpub_Look_orig.publish(m_model_orig);
	//JW 16.07.08
	////////////////////////////////////////////////////////////////
}

void LocalPlannerThread::run()
{
    int cntLoop =0;
    int index =0;
    ros::Rate loop_rate(10);

    while(1)
    {
        if(m_bThreadStop) break;


        ros::spinOnce();
        loop_rate.sleep();
        
    }
}