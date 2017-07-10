#!/usr/bin/env python
#-*- coding: utf-8 -*-
'''
	python ==> ROS programming, turtlebot의 앞에 물체가 없으면 직진, 물체가 있으면 회전해서 계속 wandering을 하는 로봇용 코드
'''
import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan

def scan_callback(msg):
	global g_range_ahead
	g_range_ahead = min(msg.ranges)

g_range_ahead = 1 # Random init number
scan_sub = rospy.Subscriber('scan', LaserScan, scan_callback)
cmd_vel_pub = rospy.Publisher('cmd_vel', Twist, queue_size=1)

rospy.init_node('wander')
state_change_time = rospy.Time.now()
driving_forward = True
rate = rospy.Rate(10)

while not rospy.is_shutdown():
	if driving_forward:
		if (g_range_ahead < 0.8 or rospy.Time.now() > state_change_time):
			driving_forward = False
			state_change_time = rospy.Time.now() + rospy.Duration(5)

	else:
		if rospy.Time.now() > state_change_time:
			driving_forward = True
			state_change_time = rospy.Time.now() + rospy.Duration(30)

	twist = Twist()

	if driving_forward:
		twist.linear.x = 1
	else:
		twist.angular.z = 1

	cmd_vel_pub.publish(twist)
	rate.sleep()