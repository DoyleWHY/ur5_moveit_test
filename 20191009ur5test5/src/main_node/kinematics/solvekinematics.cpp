#include "solvekinematics.h"

SolveKinematics::SolveKinematics():
    transKinematics(new CGlobal)
{
    Py_Initialize();   //initialize python enviroment

    if(!Py_IsInitialized())
    {
        cout << "Python initialize failed!" << endl;
    }

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/why/doyle_why/galil_test/API2/dp1/src/main_node/deep_learning')");

    pModule = PyImport_ImportModule("real_test2");

    if (!pModule)
    {
        cout << "get module from real_test2.py failed!" << endl;
        Py_Finalize();
        exit (0);
    }

    pFunc = PyObject_GetAttrString(pModule, "train_angle");
    if (!pFunc)
    {
        cout << "get func failed!" << endl;
        Py_Finalize();
        exit (0);
    }

    pFunc2 = PyObject_GetAttrString(pModule, "jacobian_angle");
    if (!pFunc2)
    {
        cout << "get func2 failed!" << endl;
        Py_Finalize();
        exit (0);
    }


}

SolveKinematics::~SolveKinematics()
{

}

bool SolveKinematics::solveTheta()  //use trained model
{
    pParam = Py_BuildValue("(f,f,f)", transKinematics->coordinates[0], transKinematics->coordinates[1], transKinematics->coordinates[2]);
    pRet = PyEval_CallObject(pFunc, pParam);

    PyArg_ParseTuple(pRet,"fff",&transKinematics->motorAngles[0],&transKinematics->motorAngles[1],&transKinematics->motorAngles[2]);//转换返回类型
}

bool SolveKinematics::jacobianTheta() //use jacobian and forward kinematics
{
    pParam2 = Py_BuildValue("(f,f,f,f,f,f)", transKinematics->coordinates[0], transKinematics->coordinates[1], transKinematics->coordinates[2], transKinematics->motorAngles[0], transKinematics->motorAngles[1], transKinematics->motorAngles[2]);
    pRet2 = PyEval_CallObject(pFunc2, pParam2);

    PyArg_ParseTuple(pRet2,"fff",&transKinematics->motorAngles[0],&transKinematics->motorAngles[1],&transKinematics->motorAngles[2]);//转换返回类型
}

void SolveKinematics::modelPositionCal()
{
    transKinematics->model_coordinates[0] = cos(transKinematics->motorAngles[0])*sin(transKinematics->motorAngles[1]) + (cos(transKinematics->motorAngles[0])*cos(transKinematics->motorAngles[1])*sin(transKinematics->motorAngles[2]))/2 + (cos(transKinematics->motorAngles[0])*cos(transKinematics->motorAngles[2])*sin(transKinematics->motorAngles[1]))/2;
    transKinematics->model_coordinates[1] = sin(transKinematics->motorAngles[0])*sin(transKinematics->motorAngles[1]) + (cos(transKinematics->motorAngles[1])*sin(transKinematics->motorAngles[0])*sin(transKinematics->motorAngles[2]))/2 + (cos(transKinematics->motorAngles[2])*sin(transKinematics->motorAngles[0])*sin(transKinematics->motorAngles[1]))/2;
    transKinematics->model_coordinates[2] = cos(transKinematics->motorAngles[1]) + (cos(transKinematics->motorAngles[1])*cos(transKinematics->motorAngles[2]))/2 - (sin(transKinematics->motorAngles[1])*sin(transKinematics->motorAngles[2]))/2 + 1;
}
