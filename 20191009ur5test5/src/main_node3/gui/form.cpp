#include "form.h"
#include "ui_form.h"
#include <QTime>
#include <QTimer>

using namespace std;

Form::Form(int argc, char** argv, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Form),
  gl(new CGlobal),
  simnode(new SimNode(argc,argv)),
  qnode(new QNode(argc,argv)),
  tf_node(new TF_node(argc,argv))
{
    ui->setupUi(this);

    initParameter();

    //3.1 simnode initialize
    simnode->init();   //thread 2
    //3. qnode initialize
    qnode->init();    //thread 1
    //4. tf_node initialize
    tf_node->init();    //thread 1

    QTimer *timer = new QTimer(this);
    timer->start(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(realTimeUpdate()));
}

Form::~Form()
{
    delete ui;
}

void Form::initParameter()
{
    int a = 1; int b = 0; int c = 0;
    ui->lineEdit->setText(QString::number(a));
    ui->lineEdit_2->setText(QString::number(b));
    ui->lineEdit_3->setText(QString::number(c));
}

void Form::on_setEndPosition_clicked()
{
    gl->coordinates[0] = ui->lineEdit->text().toDouble();
    gl->coordinates[1] = ui->lineEdit_2->text().toDouble();
    gl->coordinates[2] = ui->lineEdit_3->text().toDouble();
    cout << gl->coordinates[0] << ", " << gl->coordinates[1] << ", " << gl->coordinates[2] << endl;
}

void Form::realTimeUpdate()
{
    static QString strCPOSA1, strCPOSB1, strCPOSC1, strCPOSD1, strCPOSE1, strCPOSF1;
    static QString strCPOSA2, strCPOSB2, strCPOSC2, strCPOSD2, strCPOSE2, strCPOSF2;
    static QString strCPOSA3, strCPOSB3, strCPOSC3, strCPOSD3, strCPOSE3, strCPOSF3;
    static QString strCPOSA4, strCPOSB4, strCPOSC4, strCPOSD4;

    strCPOSA1.sprintf("%.4f",gl->motorAngles[0]);
    ui->lineEdit_4->setText(strCPOSA1);
    strCPOSB1.sprintf("%.4f",gl->motorAngles[1]);
    ui->lineEdit_5->setText(strCPOSB1);
    strCPOSC1.sprintf("%.4f",gl->motorAngles[2]);
    ui->lineEdit_6->setText(strCPOSC1);
    strCPOSD1.sprintf("%.4f",gl->motorAngles[3]);
    ui->lineEdit_7->setText(strCPOSD1);
    strCPOSE1.sprintf("%.4f",gl->motorAngles[4]);
    ui->lineEdit_8->setText(strCPOSE1);
    strCPOSF1.sprintf("%.4f",gl->motorAngles[5]);
    ui->lineEdit_9->setText(strCPOSF1);

    strCPOSA2.sprintf("%.4f",gl->motorVelocity[0]);
    ui->lineEdit_10->setText(strCPOSA2);
    strCPOSB2.sprintf("%.4f",gl->motorVelocity[1]);
    ui->lineEdit_11->setText(strCPOSB2);
    strCPOSC2.sprintf("%.4f",gl->motorVelocity[2]);
    ui->lineEdit_12->setText(strCPOSC2);
    strCPOSD2.sprintf("%.4f",gl->motorVelocity[3]);
    ui->lineEdit_13->setText(strCPOSD2);
    strCPOSE2.sprintf("%.4f",gl->motorVelocity[4]);
    ui->lineEdit_14->setText(strCPOSE2);
    strCPOSF2.sprintf("%.4f",gl->motorVelocity[5]);
    ui->lineEdit_15->setText(strCPOSF2);

    strCPOSA3.sprintf("%.4f",gl->motorEffort[0]);
    ui->lineEdit_16->setText(strCPOSA3);
    strCPOSB3.sprintf("%.4f",gl->motorEffort[1]);
    ui->lineEdit_17->setText(strCPOSB3);
    strCPOSC3.sprintf("%.4f",gl->motorEffort[2]);
    ui->lineEdit_18->setText(strCPOSC3);
    strCPOSD3.sprintf("%.4f",gl->motorEffort[3]);
    ui->lineEdit_19->setText(strCPOSD3);
    strCPOSE3.sprintf("%.4f",gl->motorEffort[4]);
    ui->lineEdit_20->setText(strCPOSE3);
    strCPOSF3.sprintf("%.4f",gl->motorEffort[5]);
    ui->lineEdit_21->setText(strCPOSF3);

    strCPOSA4.sprintf("%.4f",(gl->tfPosition[0]));
    ui->lineEdit_22->setText(strCPOSA4);
    strCPOSB4.sprintf("%.4f",gl->tfPosition[1]);
    ui->lineEdit_23->setText(strCPOSB4);
    strCPOSC4.sprintf("%.4f",gl->tfPosition[2]);
    ui->lineEdit_24->setText(strCPOSC4);
    strCPOSD4.sprintf("%.4f",gl->tfPosition[3]);
    ui->lineEdit_25->setText(strCPOSD4);

}
