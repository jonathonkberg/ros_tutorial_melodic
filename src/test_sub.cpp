#include "ros/ros.h"
#include "pub_sub_tutorial/test_custom_msg.h"

pub_sub_tutorial::test_custom_msg recieved_msg;
void msg_cb(const pub_sub_tutorial::test_custom_msg::ConstPtr& msg_ptr)
{
    recieved_msg = *msg_ptr;
    ROS_INFO("recieved_msg = %s", msg_ptr->data.c_str());
    ROS_INFO("counter = %d", recieved_msg.counter);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber_example");
    ros::NodeHandle nh;
    ros::Subscriber msg_sub = nh.subscribe<pub_sub_tutorial::test_custom_msg>("example_string", 10, msg_cb);
    ros::spin();
    return 0;
}