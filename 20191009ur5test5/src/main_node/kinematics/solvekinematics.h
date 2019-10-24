#ifndef SOLVEKINEMATICS_H
#define SOLVEKINEMATICS_H

#include "../vars/cglobal.h"
#include <QObject>
#pragma push_macro("slots")
#undef slots
#include "Python.h"
#pragma pop_macro("slots")
#include <iostream>

using namespace std;

class SolveKinematics : public QObject
{
    Q_OBJECT

public:
  SolveKinematics();
  ~SolveKinematics();
  void modelPositionCal();

private slots:
  bool solveTheta();
  bool jacobianTheta();

private:
  CGlobal *transKinematics;

  PyObject* pModule = NULL;
  //using trainig model
  PyObject* pFunc = NULL;
  PyObject* pParam = NULL;
  PyObject* pRet = NULL;
  //using jacobian inverse model
  PyObject* pFunc2 = NULL;
  PyObject* pParam2 = NULL;
  PyObject* pRet2 = NULL;

};

#endif // SOLVEKINEMATICS_H
