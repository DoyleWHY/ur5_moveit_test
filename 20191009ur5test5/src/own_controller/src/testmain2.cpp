//From moveit official website
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <iostream>
#include <Eigen/Dense>


using namespace std;

int main(int argc, char** argv)
{
    cout << "Hello, world!" << endl;

    ros::init(argc, argv, "move_group_interface_tutorial");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    //1 加载机器人模型“robot_description”，并打印参考坐标系
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
    robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
    ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());

    //2 定义一个机器人关节模型组，并获得关节名字。其中“panda_arm”在机器人模型文件中定义
    robot_state::RobotStatePtr kinematic_state(new robot_state::RobotState(kinematic_model));
    kinematic_state->setToDefaultValues();
    const robot_state::JointModelGroup* joint_model_group = kinematic_model->getJointModelGroup("panda_arm");

    //打印当前关节值
    const std::vector<std::string>& joint_names = joint_model_group->getVariableNames();
    std::vector<double> joint_values;
    kinematic_state->copyJointGroupPositions(joint_model_group, joint_values);
    for (std::size_t i = 0; i < joint_names.size(); ++i)
    {
        ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
    }

    //将第一个关节设置为一个超过限制的值时，会报错。强制设置后就不报错了。
    joint_values[0] = 5.57;
    kinematic_state->setJointGroupPositions(joint_model_group, joint_values);

    /* Check whether any joint is outside its joint limits */
    ROS_INFO_STREAM("Current state is " << (kinematic_state->satisfiesBounds() ? "valid" : "not valid"));
    /* Enforce the joint limits for this state and check again*/
    kinematic_state->enforceBounds();
    ROS_INFO_STREAM("Current state is " << (kinematic_state->satisfiesBounds() ? "valid" : "not valid"));

    //下面开始运动学计算，我们把末端设为link8，计算他的末端其次变换并将平移和旋转打印出来。
    // Forward Kinematics
    // ^^^^^^^^^^^^^^^^^^
    kinematic_state->setToRandomPositions(joint_model_group);//设一个随机位置
//    const Eigen::Affine3d& end_effector_state = kinematic_state->getGlobalLinkTransform("panda_link8");
    const Eigen::Isometry3d& end_effector_state = kinematic_state->getGlobalLinkTransform("panda_link8");

    ROS_INFO_STREAM("Translation: \n" << end_effector_state.translation() << "\n");
    ROS_INFO_STREAM("Rotation: \n" << end_effector_state.rotation() << "\n");

    //下面进行逆运动学计算，设置尝试次数为10，时间限制为0.1秒。
    // Inverse Kinematics
    // ^^^^^^^^^^^^^^^^^^
    std::size_t attempts = 10;
    double timeout = 0.1;
    bool found_ik = kinematic_state->setFromIK(joint_model_group, end_effector_state, attempts, timeout);
    //如果得到结果，我们将joint_model_group中保存的结果打印出来。否则报错。
    if (found_ik)
    {
        kinematic_state->copyJointGroupPositions(joint_model_group, joint_values);
        for (std::size_t i = 0; i < joint_names.size(); ++i)
        {
            ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
        }
    }
    else
    {
        ROS_INFO("Did not find IK solution");
    }
    //下面的方法可以获得雅克比矩阵。
    Eigen::Vector3d reference_point_position(0.0, 0.0, 0.0);
    Eigen::MatrixXd jacobian;
    kinematic_state->getJacobian(joint_model_group,
                           kinematic_state->getLinkModel(joint_model_group->getLinkModelNames().back()),
                           reference_point_position, jacobian);
    ROS_INFO_STREAM("Jacobian: \n" << jacobian << "\n");

    ros::shutdown();
    return 0;
}
