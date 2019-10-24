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
    ros::init(init_argc,init_argv,"robot_control_node");
    if (!ros::master::check())
    {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    chatter_publisher = n.advertise<sensor_msgs::JointState>("joint_states", 1000);
    //ros::spin();
    start();
    std::cout << "  4.2 : Robot controller node start!" << std::endl;
    return true;
}

bool SimNode::init(const std::string &master_url, const std::string &host_url)
{
    std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;
    ros::init(remappings,"robot_control_node");
    if (!ros::master::check())
    {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    chatter_publisher = n.advertise<sensor_msgs::JointState>("joint_states", 1000);
    start();
    return true;
}

void SimNode::run()
{
    //ros::Rate loop_rate(1);
    ros::Duration initDur(0.5);
    sensor_msgs::JointState msg;
    msg.name.resize(3);
    msg.position.resize(3);

    msg.name[0] = "joint1";
    msg.name[1] = "joint2";
    msg.name[2] = "joint3";

    int count = 0;
    while (ros::ok())
    {
        static CGlobal simMotorAngle;
        msg.header.stamp = ros::Time::now();
        msg.position[0] = simMotorAngle.motorAngles[0];
        msg.position[1] = simMotorAngle.motorAngles[1];
        msg.position[2] = simMotorAngle.motorAngles[2];

        chatter_publisher.publish(msg);
        //loop_rate.sleep();
        initDur.sleep();
        ++count;
    }
    std::cout << "Robot simulink controller shutdown, proceeding to close the gui." << std::endl;
}
