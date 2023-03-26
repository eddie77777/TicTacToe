#include "UIListener.h"
#include"QMessagebox"

UIListener::UIListener(int no, IGamePtr game) : m_no(no)
, m_game(game)
{
}

void UIListener::OnMakeMove(Position pos, int currentPlayer, IGame* game)
{
    QString message = "Player " + QString::number(currentPlayer) + " made a move at position (" +
        QString::number(pos.first) + "," + QString::number(pos.second) + ")";
    QMessageBox::information(nullptr, "Previous move:", message);
}


void UIListener::OnGameOver(int currentPlayer, EGameState gameState)
{
    if (gameState == EGameState::Win) {
        QString message = QString("Player %1 wins!").arg(currentPlayer);
        QMessageBox::information(nullptr, "Game Over", message);
    }
    else
        QMessageBox::information(nullptr, "Game Over", "It's a tie!");
}
