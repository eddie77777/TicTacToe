#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_guiDPXO.h"

class guiDPXO : public QMainWindow
{
    Q_OBJECT

public:
    guiDPXO(QWidget *parent = nullptr);
    ~guiDPXO();

private:
    Ui::guiDPXOClass ui;
};
