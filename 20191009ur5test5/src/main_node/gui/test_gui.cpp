#include "../galil/x_examples.h"
#include <QDebug>
#include "test_gui.h"
#include "ui_test_gui.h"

Test_gui::Test_gui(int argc, char** argv, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Test_gui),
//    roslink(new RosConnect()),
    gl3(new CGlobal),
    qnode(new QNode(argc,argv)),
    simnode(new SimNode(argc,argv)),
    solvekinematics(new SolveKinematics),
    graphnode(new GlGragh()),
    motorPtr(new GalilServo())
{
    //1.user interface initialize
    ui->setupUi(this);
    ui->label->setNum(4);
    //1.1 3D graph initialize
    cout << "Step2 : Initialize opengl graph\n";
    graphnode->resize(700,700);
    graphnode->show();
    cout << "*********************************" << endl;

    //2.initialize DMC4143 and servo
    motorPtr->initMotor(); 

    cout << "Step4 : Initialize ros node(publisher and subscriber)\n";
    //3.qnode initialize
    qnode->init();     //thread 1

    //3.1.simnode initialize
    simnode->init();   //thread 2

    //4.connect ros with qt, communicate with slots and signals
//    connect(roslink,SIGNAL(signaltest()),this,SLOT(on_pushButton_3_clicked()));
//    connect(RosConnect::instance(),SIGNAL(signaltest()),this,SLOT(on_pushButton_3_clicked()));
    connect(qnode,SIGNAL(signalShowAllPosition()),this,SLOT(on_pushButton_3_clicked()));
    connect(qnode,SIGNAL(signalSolveKinematics()),solvekinematics,SLOT(jacobianTheta()));

    //5.interface timer initialize
    id1 = startTimer(100);                  // 开启一个1秒定时器，返回其ID
    id2 = startTimer(1500);
    id3 = startTimer(2200);
}

Test_gui::~Test_gui()
{
    delete ui;
}

void Test_gui::on_pushButton_pressed()
{
    cout << gl3->testValue;
    ui->label->setNum(gl3->testValue);
    motorPtr->disableMotor(1);
}

void Test_gui::on_pushButton_2_clicked()
{
    motorPtr->movePositionRelatively(1,20000);
//    RosConnect::instance()->test_signal();
    qnode->showPositionTest();
}

void Test_gui::on_pushButton_3_clicked()
{
    motorPtr->printPositon(1);
}

void Test_gui::on_pushButton_4_clicked()
{
    close();
}  

void Test_gui::timerEvent(QTimerEvent *event)
{
    static QString strCPOSA, strCPOSB, strCPOSC,strCPOSD;
    static QString strRPOSX, strRPOSY, strRPOSZ;
    static QString strMPOSX, strMPOSY, strMPOSZ;

    motorPtr->getMotorPosition(1, motorCPos[0]);
    strCPOSA.sprintf("%d",motorCurrentPosition[0]);   //%.3f
    ui->MotorAtextBrowser->setText(strCPOSA);

    motorPtr->getMotorPosition(2, motorCPos[1]);
    strCPOSB.sprintf("%d",motorCurrentPosition[1]);   //%.3f
    ui->MotorBtextBrowser->setText(strCPOSB);

    motorPtr->getMotorPosition(3, motorCPos[2]);
    strCPOSC.sprintf("%d",motorCurrentPosition[2]);   //%.3f
    ui->MotorCtextBrowser->setText(strCPOSC);

    motorPtr->getMotorPosition(4, motorCPos[3]);
    strCPOSD.sprintf("%d",motorCurrentPosition[3]);   //%.3f
    ui->MotorDtextBrowser->setText(strCPOSD);

//    Show real position
    strRPOSX.sprintf("%.3f",gl3->coordinates[0]);   //%.3f
    ui->RealPositionX->setText(strRPOSX);

    strRPOSY.sprintf("%.3f",gl3->coordinates[1]);   //%.3f
    ui->RealPositionY->setText(strRPOSY);

    strRPOSZ.sprintf("%.3f",gl3->coordinates[2]);   //%.3f
    ui->RealPositionZ->setText(strRPOSZ);

//    Calculate robot end effector position
    solvekinematics->modelPositionCal();

//    Show model position
    strMPOSX.sprintf("%.3f",gl3->model_coordinates[0]);   //%.3f
    ui->ModelPositionX->setText(strMPOSX);

    strMPOSY.sprintf("%.3f",gl3->model_coordinates[1]);   //%.3f
    ui->ModelPositionY->setText(strMPOSY);

    strMPOSZ.sprintf("%.3f",gl3->model_coordinates[2]);   //%.3f
    ui->ModelPositionZ->setText(strMPOSZ);

    graphnode->drawonline();  //update opengl graph

    if (event->timerId() == id1) {       // 判断是哪个定时器
//        qDebug() << "timer1";
    }
    else if (event->timerId() == id2) {
//        qDebug() << "timer2";
    }
    else {
//        qDebug() << "timer3";
    }
}

void Test_gui::on_modelChangeButton_clicked()
{
    static bool changeModelSignal = 1;
    static QString modelText;

    if(changeModelSignal){
        disconnect(qnode,SIGNAL(signalSolveKinematics()),solvekinematics,SLOT(jacobianTheta()));
        connect(qnode,SIGNAL(signalSolveKinematics()),solvekinematics,SLOT(solveTheta()));
        changeModelSignal = false;

        modelText.sprintf("Trained model");
        ui->modelChangeButton->setText(modelText);
    }else {
        disconnect(qnode,SIGNAL(signalSolveKinematics()),solvekinematics,SLOT(solveTheta()));
        connect(qnode,SIGNAL(signalSolveKinematics()),solvekinematics,SLOT(jacobianTheta()));
        changeModelSignal = true;

        modelText.sprintf("Jacobian model");
        ui->modelChangeButton->setText(modelText);
    }
}
