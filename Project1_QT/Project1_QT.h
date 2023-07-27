#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Project1_QT.h"

class Project1_QT : public QMainWindow
{
    Q_OBJECT

public:
    Project1_QT(QWidget *parent = nullptr);
    ~Project1_QT();

private:
    Ui::Project1_QTClass ui;
};
