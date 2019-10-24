#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <iostream>
#include <QTime>
#include "../vars/cglobal.h"
#include "../ros_connect/simnode.h"
#include "../ros_connect/qnode.h"
#include "../ros_connect/tf_node.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
  Q_OBJECT

public:
  explicit Form(int argc, char** argv, QWidget *parent = nullptr);
  ~Form();
  void initParameter();

private slots:
  void on_setEndPosition_clicked();
  void realTimeUpdate();

private:
  Ui::Form *ui;
  CGlobal *gl;
  SimNode *simnode;
  QNode *qnode;
  TF_node *tf_node;


};

#endif // FORM_H
