#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QResizeEvent>
#include "Game.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(EGameMode gameMode, QWidget* parent = nullptr);
    void HandleButton();
    ~MainWindow();
    IGamePtr GetGame();
private:
    QPushButton* buttons[3][3];
    IGamePtr m_game;
    EGameMode m_gameMode;
};

#endif // MAINWINDOW_H