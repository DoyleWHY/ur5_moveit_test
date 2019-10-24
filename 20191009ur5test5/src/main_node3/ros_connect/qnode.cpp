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
    ros::init(init_argc,init_argv,"moveit_robotInfo_receive"); // 初始化节点名称
    if (!ros::master::check())
    {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle nh; // 声明用于ROS系统和通信的节点句柄
    // Add your ros communications here.
    joy_subscriber = nh.subscribe("joint_states", 100, &QNode::JointRecvCallback, this);
    start();
    std::cout << "  4.2 : Info receive node start!" << std::endl;
    return true;
}

void QNode::run()
{
    ros::spin();
}

void QNode::JointRecvCallback(const sensor_msgs::JointState::ConstPtr &msg)
{
    static CGlobal gl3;
    gl3.motorAngles[0] = msg->position[0];
    gl3.motorAngles[1] = msg->position[1];
    gl3.motorAngles[2] = msg->position[2];
    gl3.motorAngles[3] = msg->position[3];
    gl3.motorAngles[4] = msg->position[4];
    gl3.motorAngles[5] = msg->position[5];

    gl3.motorVelocity[0] = msg->velocity[0];
    gl3.motorVelocity[1] = msg->velocity[1];
    gl3.motorVelocity[2] = msg->velocity[2];
    gl3.motorVelocity[3] = msg->velocity[3];
    gl3.motorVelocity[4] = msg->velocity[4];
    gl3.motorVelocity[5] = msg->velocity[5];

    gl3.motorEffort[0] = msg->effort[0];
    gl3.motorEffort[1] = msg->effort[1];
    gl3.motorEffort[2] = msg->effort[2];
    gl3.motorEffort[3] = msg->effort[3];
    gl3.motorEffort[4] = msg->effort[4];
    gl3.motorEffort[5] = msg->effort[5];
}

