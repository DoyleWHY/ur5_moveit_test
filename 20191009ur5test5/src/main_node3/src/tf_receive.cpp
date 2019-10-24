#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    static double x, y, z;

    ros::init(argc, argv, "my_tf_listener");
    ros::NodeHandle node;

    tf::TransformListener listener;

    ros::Rate rate(100.0);
    while (node.ok()){
        tf::StampedTransform transform;
        try{
            listener.lookupTransform("/base_link", "/wrist_3_link",
                                   ros::Time(0), transform);
        }
        catch (tf::TransformException ex){
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
        }

        x = transform.getOrigin().x();
        y = transform.getOrigin().y();
        z = transform.getOrigin().z();
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;

        rate.sleep();
    }
    return 0;
};
