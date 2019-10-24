#include "rosconnect.h"
#include <iostream>

using namespace std;

RosConnect::RosConnect(QObject *parent):
    QObject(parent)
{

}

RosConnect::~RosConnect()
{

}

void RosConnect::test_signal()
{
    emit signaltest();
    cout << "have emitted!" << endl;
}

Q_GLOBAL_STATIC(RosConnect, rosConnectInstance)
RosConnect *RosConnect::instance()
{
    return rosConnectInstance();
}
