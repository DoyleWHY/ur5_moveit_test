#ifndef QNODE_H
#define QNODE_H

/*****************************************************************************
** Includes
*****************************************************************************/
#include <ros/ros.h>
#include "sensor_msgs/JointState.h"
#include "std_msgs/String.h"
#include <string>
#include <iostream> //std::cout
#include <QThread>
#include <QStringListModel>
#include "../vars/cglobal.h"

/*****************************************************************************
** Class
*****************************************************************************/
class QNode : public QThread
{
    Q_OBJECT
    public:
        QNode(int argc, char** argv);
        virtual ~QNode();
        bool init();
        void run();

        /*********************
        ** Logging
        **********************/
        enum LogLevel
        {
            Debug,
            Info,
            Warn,
            Error,
            Fatal
        };

        void JointRecvCallback(const sensor_msgs::JointState::ConstPtr &msg);

    signals:
        void signalShowAllPosition();
        void signalSolveKinematics();

    private:
        int init_argc;
        char** init_argv;
        ros::Subscriber joy_subscriber;
};

#endif // QNODE_H
