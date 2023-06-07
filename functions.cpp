#include "functions.h"

QString parsing(QString inputString){

    qDebug() << inputString;
    QStringList inputString_list = inputString.split('&');
    qDebug() << inputString_list;
    QString NameOfFunc = inputString_list.front();
    inputString_list.pop_front();


    if (NameOfFunc == "test")
        return start(inputString_list.at(0), inputString_list.at(1));
    if (NameOfFunc == "sort")
        return sort(inputString_list.at(0), inputString_list.at(1));


    return 0;
}


QString start(QString input1, QString input2){
    return input1 + "&" + input2;
}

QString sort(QString step, QString input2) {
    QList<QString> inputList = input2.split(" ");
    QVector<int> arr;
    for (const QString& str : inputList) {
        arr.append(str.toInt());
    }

    heapSortWithStep(arr, step.toInt());

    QString result;
    for (const int& num : arr) {
        result += QString::number(num) + " ";
    }
    qDebug() << arr;
    return result;
}

void heapify(QVector<int>& arr, int n, int i, int step) {
    int largest = i;
    int left = step * i + 1;
    int right = step * i + 2;

    for (int j = 0; j < step; j++) {
        if ((left + j) < n && arr[largest] < arr[left + j])
            largest = left + j;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest, step);
    }
}

void heapSortWithStep(QVector<int>& arr, int step)  {
    int n = arr.size();

    // Построение max-кучи (пирамиды)
    for (int i = n / step - 1; i >= 0; i--)
        heapify(arr, n, i, step);

    // Извлечение элементов из кучи по одному и перестроение кучи
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, step);
    }
}
