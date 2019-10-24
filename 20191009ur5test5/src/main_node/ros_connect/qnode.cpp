/*****************************************************************************
** Includes
*****************************************************************************/
#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "qnode.h"

/*****************************************************************************
** Implementation
*****************************************************************************/
QNode::QNode(int argc, char** argv)
    : init_argc(argc), init_argv(argv)
{}

QNode::~QNode()
{
    if(ros::isStarted())
    {
        ros::shutdown(); // explicitly needed since we use ros::start();
        ros::waitForShutdown();
    }
    wait();
}

bool QNode::init()
{
    ros::init(init_argc,init_argv,"qt_joy_receive"); // 初始化节点名称
    if (!ros::master::check())
    {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle nh; // 声明用于ROS系统和通信的节点句柄
    // Add your ros communications here.
    joy_subscriber = nh.subscribe("joy", 100, &QNode::JoyRecvCallback, this);
    start();
    std::cout << "  4.1 : Joy receive node start!" << std::endl;
    return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url)
{
    std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;
    ros::init(remappings,"test_gui");
    if (!ros::master::check())
    {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle nh;
    // Add your ros communications here.
    joy_subscriber = nh.subscribe("joy", 100, &QNode::JoyRecvCallback, this);
    start();  //run qnode thread with run() function
    return true;
}

void QNode::run()
{
    ros::spin();
}

void QNode::JoyRecvCallback(const sensor_msgs::Joy::ConstPtr &msg)
{
    emit signalSolveKinematics();  //start kinematics solving

    static CGlobal roscoor;
    roscoor.coordinates[0] = msg->axes[1];
    roscoor.coordinates[1] = msg->axes[0];
    roscoor.coordinates[2] = msg->axes[4];

    ROS_INFO("recieve msg = %f", roscoor.coordinates[0]); // 显示stamp.sec消息
    ROS_INFO("recieve msg = %f", roscoor.coordinates[1]); // 显示stamp.nsec消息
    ROS_INFO("recieve msg = %f", roscoor.coordinates[2]); // 显示data消息 button B

    if (msg->buttons[1] == 1){
        std::cout << "yes, pressed!" << std::endl;
        emit signalShowAllPosition();
    }
}

void QNode::showPositionTest()    //no real application function, jutst a test funciton
{
    emit signalShowAllPosition();
}
