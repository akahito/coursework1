#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "ShellSort.h"
#include "SortThread.h"
#include "SortAlgorithm.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    method(QUICK),
    type(DOUBLE),
    ui(new Ui::MainWindow),
    alpha("abcdefghijklmnopqrstuvwxyz") {
    ui->setupUi(this);

    connect(ui->sortButton, SIGNAL(clicked()), this, SLOT(onSortButtonClicked()));
    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(onGenerateButtonClicked()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
    connect(ui->sortMethod, SIGNAL(currentIndexChanged(int)), this, SLOT(onSortMethodChanged(int)));
    connect(ui->sortType, SIGNAL(currentIndexChanged(int)), this, SLOT(onSortTypeChanged(int)));
    connect(ui->numbers, SIGNAL(blockCountChanged(int)), this, SLOT(onNumbersBlockCountChanged(int)));
    connect(&sortThread, SIGNAL(end(QString, int)), this, SLOT(onSortEnd(QString, int)));

    ui->sortMethod->addItem("Quick");
    ui->sortMethod->addItem("Merge");
    ui->sortMethod->addItem("Shell");

    ui->sortType->addItem("Double");
    ui->sortType->addItem("String");

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onSortButtonClicked() {
    ui->sortButton->setEnabled(false);
    ui->clearButton->setEnabled(false);
    ui->generateButton->setEnabled(false);
    ui->numbers->setEnabled(false);
    ui->lastTimeLabel->setText("loading...");
    ui->sortMethod->setEnabled(false);
    ui->sortType->setEnabled(false);
    ui->addCount->setEnabled(false);

    sortThread.start(ui->numbers->toPlainText(), method, type);
}

void MainWindow::onSortEnd(QString result, int time) {
    ui->numbers->setPlainText(result);
    ui->sortButton->setEnabled(true);
    ui->clearButton->setEnabled(true);
    ui->generateButton->setEnabled(true);
    ui->numbers->setEnabled(true);
    ui->sortMethod->setEnabled(true);
    ui->sortType->setEnabled(true);
    ui->addCount->setEnabled(true);
    ui->lastTimeLabel->setText(QString::number((double) time / 1000) + "sec");
}

void MainWindow::onGenerateButtonClicked() {
    int size = ui->addCount->value();
    QString text;

    for(int i = 0; i < size; i++) {
        if(type == DOUBLE)
            text += QString::number(qrand() % 1000000);
        else
            text += alpha[qrand() % alpha.length()];
        if(i + 1 < size)
            text += "\n";
    }

    ui->numbers->appendPlainText(text);
}

void MainWindow::onSortMethodChanged(int index) {
    method = (SortMethod) index;
}

void MainWindow::onSortTypeChanged(int index) {
    type = (SortType) index;
}

void MainWindow::onNumbersBlockCountChanged(int newBlockCount) {
    ui->numbersSize->display(newBlockCount);
}

void MainWindow::onClearButtonClicked() {
    ui->numbers->clear();
}
