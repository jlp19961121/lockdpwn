#include <ros/ros.h>    
#include <gps_test.h>  

int main(int argc, char **argv) 
{
 	ros::init(argc, argv, "gps_sub");
 	ros::NodeHandle node; 

	gps_test::GPS_data hm(node);

	ros::spin();

  	return 0;
}


