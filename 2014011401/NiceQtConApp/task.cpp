#include "task.h"
#include <qDebug>

Task::Task(QObject *parent)
:   QObject(parent) {
}

void Task::run() {
    qDebug("Hello, Nice QT Console Application!");
    emit finished();
}
