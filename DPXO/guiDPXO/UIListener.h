#pragma once
#include "IGame.h"
#include <QPushButton>
class UIListener : public IGameListener
{
public:
    UIListener(int no, IGamePtr game);
    void OnMakeMove(Position pos, int currentPlayer) override;
    void OnGameOver(int currentPlayer, EGameState gameState) override;
    char ECellStateToChar(ECellState cellState);
private:
    int m_no;
    IGamePtr m_game;
};