#pragma once
#include <QtGui/QMainWindow>
#include <QtCore>
#include <ros/ros.h>
#include <Eigen/Core>

#include <std_msgs/Float32MultiArray.h>

#include "../../../build/controller/ui_controller_gui.h" // ui_*.h
using namespace Eigen;

class PurePursuitThread : public QThread
{
	Q_OBJECT;
	
	private :
		int init_argc;
		char** init_argv;

		ros::Subscriber possub;
		ros::Publisher msgpub;

		////////////////////////////////
		bool m_bThreadStop;
		bool m_bPosTopicUpdated;
		QMutex m_mutex;

		Vector2d m_pos;
		float m_heading;
		Vector2d m_lookAheadPos;
		float m_lookAheadLength;
		int _cnt;
		float m_steerAngle;
				
		// pure pursuit
		float m_len_c2r; // length of center and rear wheel
		float m_len_f2r; // length of front wheel and rear wheel
		float m_ratio_s2w; // ratio of steer to wheel
		float m_limit_steerAngle;
        double m_lookX, m_lookY, m_resdist;

	public :
	double getSAS(){return m_steerAngle;}
	
	void Compute();
        void SubscribeTopicProcess(const std_msgs::Float32MultiArray::ConstPtr& msg);
        PurePursuitThread(int argc, char** argv, Ui::MainWindow* ui);
	Ui::MainWindow* _ui;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	public slots:
		void stop();
	private:
		
		void run();
		
		
};