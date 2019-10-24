#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "simnode.h"

SimNode::SimNode(int argc, char** argv)
    : init_argc(argc), init_argv(argv)
{

}

SimNode::~SimNode()
{
    if(ros::isStarted())
    {
        ros::shutdown(); // explicitly needed since we use ros::start();
        ros::waitForShutdown();
    }
    wait();
}

bool SimNode::init()
{
    ros::init(init_argc,init_argv,"robot_position_control_node");
    if (!ros::master::check())
    {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    chatter_publisher = n.advertise<main_node3::MsgTutorial>("ros_tutorial_msg", 100);
    //ros::spin();
    start();
    std::cout << "  4.1 : Robot controller node start!" << std::endl;
    return true;
}

void SimNode::run()
{
    //ros::Rate loop_rate(1);
    ros::Duration initDur(0.5);
    main_node3::MsgTutorial msg;

    int count = 0;
    while (ros::ok())
    {
        static CGlobal gl2;
        msg.stamp = ros::Time::now(); // 把当前时间传给msg的下级消息stamp
        msg.data = count; // 将变量count的值传给下级消息data
        msg.cor_data[0] = gl2.coordinates[0];
        msg.cor_data[1] = gl2.coordinates[1];
        msg.cor_data[2] = gl2.coordinates[2];
        ROS_INFO("send msg = %d", msg.stamp.sec); // 显示stamp.sec消息
        ROS_INFO("send msg = %d", msg.stamp.nsec); // 显示stamp.nsec消息
        ROS_INFO("send msg = %d", msg.data); // 显示data消息
        ROS_INFO("Robot position = %f, %f, %f", msg.cor_data[0], msg.cor_data[1], msg.cor_data[2]); // 显示data消息
        chatter_publisher.publish(msg);
        //loop_rate.sleep();
        initDur.sleep();
        ++count;
    }
    std::cout << "Robot simulink controller shutdown, proceeding to close the gui." << std::endl;
}
