#include "ros/ros.h"
#include <gps_test.h>


#define PI 3.14159265358979323846264338327950288
#define Radians(theta) ((theta) / 180.0 * PI)
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))

namespace gps_test {

void GPS_data::msgCallback(const std_msgs::Float32MultiArray::ConstPtr& msg)
{
	

	m_points.header.frame_id = m_line_strip.header.frame_id = "/base_link";
	//m_points.header.stamp = m_line_strip.header.stamp = m_line_list.header.stamp = ros::Time::now();
	m_points.ns = m_line_strip.ns = "RegionOfInterest";
	m_points.action = m_line_strip.action = visualization_msgs::Marker::ADD;
	//m_points.pose.orientation.w = m_line_strip.pose.orientation.w = m_line_list.pose.orientation.w = 1.0;	

	m_points.id = 0;
	m_line_strip.id = 1;

//	m_points.type = visualization_msgs::Marker::SPHERE;
	m_points.type = visualization_msgs::Marker::CUBE;
	m_line_strip.type = visualization_msgs::Marker::LINE_STRIP;

	m_points.scale.x = 4.0;
	m_points.scale.y = 4.0;
	m_points.scale.z = 0.0;
	m_line_strip.scale.x = 2.0;

	m_points.color.r = 1.0;
	m_points.color.g = 1.0;
	m_points.color.a = 1.0;

	m_line_strip.color.g = 1.0;
	m_line_strip.color.a = 1.0; 

	m_points.pose.position.x = msg->data.at(0);//*0.001;
	m_points.pose.position.y = msg->data.at(1);//*0.001;
	m_points.pose.position.z = 0;

	//points.pose.orientation.w =

	m_line_strip.points.push_back(m_points.pose.position);
	
	gps_pub.publish(m_points);
	gps_pub.publish(m_line_strip);

	ROS_INFO("x : %f, y : %f, heading : %f, vel : %f", msg->data.at(0),msg->data.at(1),msg->data.at(2),msg->data.at(3));

	//p =  
}

GPS_data::GPS_data(ros::NodeHandle node)
{
	gps_sub = node.subscribe("LocalizationData", 1, &GPS_data::msgCallback, this,
                              ros::TransportHints().tcpNoDelay(true));
	gps_pub = node.advertise< visualization_msgs::Marker>("gps_marker", 2);
}

GPS_data::~GPS_data()	{}

 
} //namespace gps_test
