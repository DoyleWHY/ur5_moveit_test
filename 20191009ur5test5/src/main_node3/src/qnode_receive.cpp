//From moveit official website
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <ros/callback_queue_interface.h>
#include <ros/network.h>
#include "main_node3/MsgTutorial.h"
#include "std_msgs/String.h"
#include <string>
#include <iostream> //std::cout
#include <sstream>

double raw_data[3] = {0.28, 0, 0.5};
double process_data[3] = {0, 0, 0};

void InfoRecvCallback(const main_node3::MsgTutorial::ConstPtr &msg)
{
    ROS_INFO("receive msg = %d", msg->data); // 显示data消息

    raw_data[0] = msg->cor_data[0];
    raw_data[1] = msg->cor_data[1];
    raw_data[2] = msg->cor_data[2];

    ROS_INFO("receive Robot position = %lf, %lf, %lf", raw_data[0], raw_data[1], raw_data[2]); // 显示data消息
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "moveit_robotInfo_receive"); // 初始化节点名称
    if (!ros::master::check())
    {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle nh; // 声明用于ROS系统和通信的节点句柄

    ros::CallbackQueue queue_1;
    nh.setCallbackQueue(&queue_1);

    ros::AsyncSpinner spinner(1);
    spinner.start();

    static const std::string PLANNING_GROUP = "manipulator";
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    // 创建运动规划的情景，等待创建完成
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    const robot_state::JointModelGroup* joint_model_group =
        move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

    //1 Getting Basic Information
    // ^^^^^^^^^^^^^^^^^^^^^^^^^
    //
    // We can print the name of the reference frame for this robot.
    ROS_INFO_NAMED("tutorial", "Planning frame: %s", move_group.getPlanningFrame().c_str());

    // We can also print the name of the end-effector link for this group.
    ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group.getEndEffectorLink().c_str());

    // We can get a list of all the groups in the robot:
    ROS_INFO_NAMED("tutorial", "Available Planning Groups:");
    std::copy(move_group.getJointModelGroupNames().begin(), move_group.getJointModelGroupNames().end(),
              std::ostream_iterator<std::string>(std::cout, ", "));


    // Add your ros communications here.
    ros::Subscriber joy_subscriber = nh.subscribe("ros_tutorial_msg", 1, InfoRecvCallback);

    geometry_msgs::Pose target_pose1;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    ros::Rate loop_rate(100);
    int count = 0;
    while (ros::ok())
    {
        std::cout << "hello world: " << count << std::endl;

        queue_1.callOne(ros::WallDuration(1.0)); // can also be callAvailable()

        if((abs(process_data[0] - raw_data[0]) <= 0.01) && (abs(process_data[1] - raw_data[1]) <= 0.01) && (abs(process_data[2] - raw_data[2]) <= 0.01)){
            std::cout << "Do not excuet planning!" << std::endl;
        }
        else{
            process_data[0] = raw_data[0];
            process_data[1] = raw_data[1];
            process_data[2] = raw_data[2];
            target_pose1.orientation.w = 1.0;
            target_pose1.position.x = process_data[0];
            target_pose1.position.y = process_data[1];
            target_pose1.position.z = process_data[2];
            move_group.setPoseTarget(target_pose1);

            bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
            ROS_INFO_NAMED("tutorial", "Visualizing plan 1 (pose goal) %s", success ? "SUCCEED" : "FAILED");

            move_group.move();
        }

        loop_rate.sleep();
        ++count;
    }

    ros::waitForShutdown();
    std::cout << "  4.2 : Info receive node start1!" << std::endl;
    return 0;
}


