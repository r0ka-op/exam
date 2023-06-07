#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QStringList>
#include <QDebug>


QString parsing(QString inputString);

QString start(QString input1, QString input2);
QString sort(QString step, QString input2);

void heapSortWithStep(QVector<int>& arr, int step);
void heapify(QVector<int>& arr, int n, int i, int step);

#endif // FUNCTIONS_H
