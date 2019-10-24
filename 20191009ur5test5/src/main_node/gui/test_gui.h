#ifndef TEST_GUI_H
#define TEST_GUI_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QProcess>
#include <memory>
#include "../galil_servo/galilservo.h"
//#include "../ros_connect/rosconnect.h"
#include "../ros_connect/qnode.h"
#include "../ros_connect/simnode.h"
#include "../kinematics/solvekinematics.h"
#include "../vars/cglobal.h"
#include "glgragh.h"

#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/Dense>

namespace Ui {
class Test_gui;
}

class Test_gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test_gui(int argc, char** argv, QWidget *parent = 0);
    ~Test_gui();

//signals:


private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_clicked(); //movePositionRelatively

    void on_pushButton_3_clicked(); //printPositon

    void on_pushButton_4_clicked(); //close

    void on_modelChangeButton_clicked(); //model change button

private:
    Ui::Test_gui *ui;
    int id1, id2, id3;   //timer
//    RosConnect *roslink;
    CGlobal *gl3;
    QNode *qnode;
    SimNode *simnode;
    SolveKinematics *solvekinematics;
    GlGragh *graphnode;

    std::unique_ptr<GalilServo> motorPtr;

    Eigen::Vector4i motorCurrentPosition;
    Eigen::Vector4i &motorCPos = motorCurrentPosition;

protected:
    void timerEvent(QTimerEvent *event);

};

#endif // TEST_GUI_H
