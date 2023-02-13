#!/usr/bin/env python

import rospy
# from std_msgs.msg import String
from pub_sub_tutorial.msg import test_custom_msg

def subscriber():
    # sub = rospy.Subscriber('string_publish', String, callback_function)
    sub = rospy.Subscriber('string_publish', test_custom_msg, callback_function)
    rospy.spin()

def callback_function(message):

    # not in previous example
    string_recieved = message.data
    counter_recieved = message.counter
    rospy.loginfo("I recieved: %d"%counter_recieved)

    rospy.loginfo("I recieved: %s"%message.data)

if __name__ == "__main__":
    rospy.init_node("simple_subscriber")
    subscriber()