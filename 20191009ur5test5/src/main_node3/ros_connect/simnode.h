#ifndef SIMNODE_H
#define SIMNODE_H

/*****************************************************************************
** Includes
*****************************************************************************/
#include <ros/ros.h>
#include "main_node3/MsgTutorial.h"
#include "std_msgs/String.h"
#include <string>
#include <iostream> //std::cout
#include <QThread>
#include <QStringListModel>
#include "../vars/cglobal.h"

/*****************************************************************************
** Class
*****************************************************************************/
class SimNode : public QThread
{
    Q_OBJECT

public:
    SimNode(int argc, char** argv);
    virtual ~SimNode();
    bool init();
    void run();

private:
    int init_argc;
    char** init_argv;
    ros::Publisher chatter_publisher;

};

#endif // SIMNODE_H
