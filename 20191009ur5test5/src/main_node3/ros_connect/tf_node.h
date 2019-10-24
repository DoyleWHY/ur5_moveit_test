#ifndef TF_NODE_H
#define TF_NODE_H

/*****************************************************************************
** Includes
*****************************************************************************/
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include "std_msgs/String.h"
#include <string>
#include <iostream> //std::cout
#include <QThread>
#include <QStringListModel>
#include "../vars/cglobal.h"

/*****************************************************************************
** Class
*****************************************************************************/
class TF_node : public QThread
{
    Q_OBJECT
    public:
        TF_node(int argc, char** argv);
        virtual ~TF_node();
        bool init();
        void run();

    private:
        int init_argc;
        char** init_argv;
        ros::Subscriber tf_subscriber;

};

#endif // TF_NODE_H
