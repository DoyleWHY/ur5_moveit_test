//From moveit official website
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    cout << "Hello, world! I am the UR5 from ROBO Lab!" << endl;

    ros::init(argc, argv, "move_group_interface_tutorial");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    static const std::string PLANNING_GROUP = "manipulator";
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    // 创建运动规划的情景，等待创建完成
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    sleep(5.0);
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


    //2.1 Planning to a Pose goal
    // ^^^^^^^^^^^^^^^^^^^^^^^
    // We can plan a motion for this group to a desired pose for the
    // end-effector.
    geometry_msgs::Pose target_pose1;
    target_pose1.orientation.w = 1.0;
    target_pose1.position.x = 0.28;
    target_pose1.position.y = 0;
    target_pose1.position.z = 0.5;
    move_group.setPoseTarget(target_pose1);

    //2.2 Now, we call the planner to compute the plan and visualize it.
    // Note that we are just planning, not asking move_group
    // to actually move the robot.
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    ROS_INFO_NAMED("tutorial", "Visualizing plan 1 (pose goal) %s", success ? "" : "FAILED");

    //2.3 Moving to a pose goal
    // ^^^^^^^^^^^^^^^^^^^^^
    move_group.move();



//    //3.1 Planning with Path Constraints
//    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//    moveit_msgs::OrientationConstraint ocm;
//    ocm.link_name = "panda_link7";
//    ocm.header.frame_id = "panda_link0";
//    ocm.orientation.w = 1.0;
//    ocm.absolute_x_axis_tolerance = 0.1;
//    ocm.absolute_y_axis_tolerance = 0.1;
//    ocm.absolute_z_axis_tolerance = 0.1;
//    ocm.weight = 1.0;

//    // Now, set it as the path constraint for the group.
//    moveit_msgs::Constraints test_constraints;
//    test_constraints.orientation_constraints.push_back(ocm);
//    move_group.setPathConstraints(test_constraints);

//    robot_state::RobotState start_state(*move_group.getCurrentState());
//    geometry_msgs::Pose start_pose2;
//    start_pose2.orientation.w = 1.0;
//    start_pose2.position.x = 0.55;
//    start_pose2.position.y = -0.05;
//    start_pose2.position.z = 0.8;
//    start_state.setFromIK(joint_model_group, start_pose2);
//    move_group.setStartState(start_state);

//    // Now we will plan to the earlier pose target from the new
//    // start state that we have just created.
//    move_group.setPoseTarget(target_pose1);

//    // Planning with constraints can be slow because every sample must call an inverse kinematics solver.
//    // Lets increase the planning time from the default 5 seconds to be sure the planner has enough time to succeed.
//    move_group.setPlanningTime(10.0);

//    success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
//    ROS_INFO_NAMED("tutorial", "Visualizing plan 3 (constraints) %s", success ? "" : "FAILED");

//    //3.3 Moving to a pose goal
//    // ^^^^^^^^^^^^^^^^^^^^^
//    move_group.move();

//    // When done with the path constraint be sure to clear it.
//    move_group.clearPathConstraints();



//    //4 Cartesian Paths
//    // ^^^^^^^^^^^^^^^
//    std::vector<geometry_msgs::Pose> waypoints;
//    waypoints.push_back(start_pose2);

//    geometry_msgs::Pose target_pose3 = start_pose2;

//    target_pose3.position.z -= 0.2;
//    waypoints.push_back(target_pose3);  // down

//    target_pose3.position.y -= 0.2;
//    waypoints.push_back(target_pose3);  // right

//    target_pose3.position.z += 0.2;
//    target_pose3.position.y += 0.2;
//    target_pose3.position.x -= 0.2;
//    waypoints.push_back(target_pose3);  // up and left

//    move_group.setMaxVelocityScalingFactor(0.1);

//    moveit_msgs::RobotTrajectory trajectory;
//    const double jump_threshold = 0.0;
//    const double eef_step = 0.01;
//    double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
//    ROS_INFO_NAMED("tutorial", "Visualizing plan 4 (Cartesian path) (%.2f%% acheived)", fraction * 100.0);


    //5 Adding/Removing Objects and Attaching/Detaching Objects
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //
    // Define a collision object ROS message.
    moveit_msgs::CollisionObject collision_object;
    collision_object.header.frame_id = move_group.getPlanningFrame();

    // The id of the object is used to identify it.
    collision_object.id = "box1";

    // Define a box to add to the world.
    shape_msgs::SolidPrimitive primitive;
    primitive.type = primitive.BOX;
    primitive.dimensions.resize(3);
    primitive.dimensions[0] = 0.4;
    primitive.dimensions[1] = 0.1;
    primitive.dimensions[2] = 0.4;

    // Define a pose for the box (specified relative to frame_id)
    geometry_msgs::Pose box_pose;
    box_pose.orientation.w = 1.0;
    box_pose.position.x = 0.4;
    box_pose.position.y = -0.2;
    box_pose.position.z = 1.0;

    // 将障碍物的属性、位置加入到障碍物的实例中
    collision_object.primitives.push_back(primitive);
    collision_object.primitive_poses.push_back(box_pose);
    collision_object.operation = collision_object.ADD;

    // 创建一个障碍物的列表，把之前创建的障碍物实例加入其中
    std::vector<moveit_msgs::CollisionObject> collision_objects;
    collision_objects.push_back(collision_object);

    // Now, let's add the collision object into the world
    ROS_INFO_NAMED("tutorial", "Add an object into the world");
    planning_scene_interface.addCollisionObjects(collision_objects);



    ros::shutdown();
    return 0;
}

