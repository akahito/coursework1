#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include <QRunnable>
#include <QThreadPool>
#include <cmath>
#include <vector>
#include "SortThread.h"
#include "SortMethod.h"
#include "SortType.h"
#include "SortAlgorithm.h"

namespace Ui {
    class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    SortMethod method;
    SortType type;
    SortThread sortThread;
    QString const alpha;

private slots:
    void onSortEnd(QString result, int time);
    void onGenerateButtonClicked();
    void onSortButtonClicked();
    void onNumbersBlockCountChanged(int newBlockCount);
    void onClearButtonClicked();
    void onSortMethodChanged(int index);
    void onSortTypeChanged(int index);
};

#endif // MAINWINDOW_H
