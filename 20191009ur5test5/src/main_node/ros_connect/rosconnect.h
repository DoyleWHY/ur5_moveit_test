#ifndef ROSCONNECT_H
#define ROSCONNECT_H

#include <QObject>


class RosConnect : public QObject
{
    Q_OBJECT

public:
  explicit RosConnect(QObject *_parent = 0);
  ~RosConnect();
  void test_signal();   //once run, emit a signal

public:
    static RosConnect *instance();

signals:
  void signaltest();

};

#endif // ROSCONNECT_H
