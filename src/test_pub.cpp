#include "ros/ros.h"
#include "pub_sub_tutorial/test_custom_msg.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher_example");
    ros::NodeHandle nh;
    ros::Publisher msg_pub = nh.advertise<pub_sub_tutorial::test_custom_msg>("example_string", 10);
    ros::Rate rate(1);

    pub_sub_tutorial::test_custom_msg message;
    message.counter = 0;
    message.data = "apple";

    while(ros::ok())
    {
        ROS_INFO("Message is %s", message.data.c_str());
        ROS_INFO("Counter is %d", message.counter);
        msg_pub.publish(message);
        message.counter++;
        rate.sleep();
    }
    
    return 0;
}