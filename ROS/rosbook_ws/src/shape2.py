#!/usr/bin/env python
#-*- coding: utf-8 -*-
'''
	python ==> ROS programming, 상태기계를 명시적으로 나열하지 않고 절차적으로 함수를 통해 구현한 코드
'''
import rospy
from smach import State, StateMachine
from time import sleep


class Drive(State):
	def __init__(self, distance):
		State.__init__(self, outcomes=['success'])
		self.distance = distance

	def execute(self, userdata):
		print 'Driving', self.distance
		sleep(1)
		return 'success'



class Turn(State):
	def __init__(self, angle):
		State.__init__(self, outcomes=['success'])
		self.angle = angle

	def execute(self, userdata):
		print 'Turning', self.angle
		sleep(1)
		return 'success'



def polygon(sides):
    polygon = StateMachine(outcomes=['success'])
    with polygon:
		# 마지막 면을 제외한 모든 면의 주행상태를 추가한다
        for i in xrange(sides - 1):
            StateMachine.add('SIDE_{0}'.format(i + 1),
                             Drive(1),
                             transitions={'success':'TURN_{0}'.format(i + 1)})

		# 모든 회전상태를 추가한다
        for i in xrange(sides - 1):
            StateMachine.add('TURN_{0}'.format(i + 1),
                             Turn(360.0 / sides),
                             transitions={'success':'SIDE_{0}'.format(i + 2)})

        # 마지막 면을 추가한다
        StateMachine.add('SIDE_{0}'.format(sides),
                         Drive(1),
                         transitions={'success':'success'})

    return polygon


if __name__ == '__main__':
    triangle = polygon(3)
    square = polygon(4)

    shapes = StateMachine(outcomes=['success'])
    with shapes:
        StateMachine.add('TRIANGLE', triangle, transitions={'success':'SQUARE'})
        StateMachine.add('SQUARE', square, transitions={'success':'success'})

    shapes.execute()
