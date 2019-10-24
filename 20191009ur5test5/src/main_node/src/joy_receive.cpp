#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include <iostream> //std::cout

#include "../vars/cglobal.h"
#include "../ros_connect/rosconnect.h"

CGlobal gl2;
void joyCallback(const sensor_msgs::Joy::ConstPtr& msg)
{
    ROS_INFO("recieve msg = %f", msg->axes[1]); // 显示stamp.sec消息
    ROS_INFO("recieve msg = %f", msg->axes[2]); // 显示stamp.nsec消息
    ROS_INFO("recieve msg = %d", msg->buttons[1]); // 显示data消息 button B

    gl2.testValue = msg->buttons[1];
    ROS_INFO("recieve msg = %d", gl2.testValue);

    if (msg->buttons[1] == 1){
        RosConnect::instance()->test_signal();
        std::cout << "yes, pressed!" << std::endl;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "joy_receive"); // 初始化节点名称
    ros::NodeHandle nh; // 声明用于ROS系统和通信的节点句柄
    // 话题名称是"ros_tutorial_msg"，订阅者队列（queue)的大小设为100。
    ros::Subscriber joy_receive_sub = nh.subscribe("joy", 100, joyCallback);
    // 用于调用后台函数，等待接收消息。在接收到消息时执行后台函数。
    ros::spin();

    return 0;
}
