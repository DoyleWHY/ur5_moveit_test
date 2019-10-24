/*****************************************************************************
** Includes
*****************************************************************************/
#include <ros/network.h>
#include <std_msgs/String.h>
#include <sstream>
#include "tf_node.h"

TF_node::TF_node(int argc, char** argv)
    : init_argc(argc), init_argv(argv)
{
}

TF_node::~TF_node()
{
    if(ros::isStarted())
    {
        ros::shutdown(); // explicitly needed since we use ros::start();
        ros::waitForShutdown();
    }
    wait();
}

bool TF_node::init()
{
    ros::init(init_argc, init_argv, "my_tf_listener");

    start();
    std::cout << "  4.3 : Tf receive node start!" << std::endl;
    return true;
}

void TF_node::run()
{
    static CGlobal gl4;
    ros::NodeHandle node;
    tf::TransformListener listener;

    ros::Rate rate(100.0);
    while (node.ok()){
        tf::StampedTransform transform;
        try{
            listener.lookupTransform("/base_link", "/ee_link",
                                   ros::Time(0), transform);
        }
        catch (tf::TransformException ex){
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
        }

        gl4.tfPosition[0] = transform.getOrigin().x();
        gl4.tfPosition[1] = transform.getOrigin().y();
        gl4.tfPosition[2] = transform.getOrigin().z();
        gl4.tfPosition[3] = transform.getOrigin().w();

        rate.sleep();
    }

}

