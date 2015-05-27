#include <QThreadPool>
#include "SortThread.h"

SortThread::SortThread():
    text(""),
    method(QUICK),
    type (STRING){
    stringAlgorithms.push_back(new QuickSort<QString>());
    stringAlgorithms.push_back(new MergeSort<QString>());
    stringAlgorithms.push_back(new ShellSort<QString>());

    doubleAlgorithms.push_back(new QuickSort<double>());
    doubleAlgorithms.push_back(new MergeSort<double>());
    doubleAlgorithms.push_back(new ShellSort<double>());
}

SortThread::~SortThread() {
    for(int i = 0; i < stringAlgorithms.size(); i++)
        delete stringAlgorithms[i];

    for(int i = 0; i < doubleAlgorithms.size(); i++)
        delete doubleAlgorithms[i];
}

void SortThread::start(QString text, SortMethod method, SortType type) {
    this->text = text;
    this->method = method;
    this->type = type;

    setAutoDelete(false);
    QThreadPool::globalInstance()->start(this);
}

void SortThread::run() {
    if(type == DOUBLE)
        sortDouble();
    else if(type == STRING)
        sortString();
}

void SortThread::sortDouble() {
    int time;
    QStringList lines = text.split("\n");
    int size = lines.size();
    double* numbers = new double[size];
    int i = 0;

    foreach(QString line, lines) {
        numbers[i] = line.trimmed().toDouble();
        i++;
    }

    QTime timer;
    timer.start();
    doubleAlgorithms[method]->sort(numbers, size);
    time = timer.elapsed();

    text = "";
    for(int i = 0; i < size; i++) {
        text += QString::number(numbers[i]);

        if(i + 1 < size)
            text += "\n";
    }
    delete[] numbers;

    emit end(text, time);
}

void SortThread::sortString() {
    int time;
    QStringList lines = text.split("\n");
    int size = lines.size();
    QString* strings = new QString[size];
    int i = 0;

    foreach(QString line, lines) {
        strings[i] = line.trimmed();
        i++;
    }

    QTime timer;
    timer.start();
    stringAlgorithms[method]->sort(strings, size);
    time = timer.elapsed();

    text = "";
    for(int i = 0; i < size; i++) {
        text += strings[i];

        if(i + 1 < size)
            text += "\n";
    }
    delete[] strings;

    emit end(text, time);
}


