#include "tictactoe.h"

TicTacToe::TicTacToe(QWidget* parent)
    : QMainWindow(parent)
{
    // Set up main window
    setWindowTitle("Tic Tac Toe");
    setFixedSize(400, 350);

    // Set up title label
    titleLabel = new QLabel("Welcome to Tic Tac Toe!", this);
    titleLabel->setFont(QFont("Arial", 20));
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setGeometry(QRect(50, 50, 300, 50));

    // Set up "play with computer" button
    playWithComputerButton = new QPushButton("Play with Computer", this);
    playWithComputerButton->setGeometry(QRect(100, 120, 200, 50));
    connect(playWithComputerButton, &QPushButton::clicked, this, &TicTacToe::startGameWithComputer);

    // Set up "play with player" button
    playWithPlayerButton = new QPushButton("Play with Player", this);
    playWithPlayerButton->setGeometry(QRect(100, 180, 200, 50));
    connect(playWithPlayerButton, &QPushButton::clicked, this, &TicTacToe::startGameWithPlayer);

}

void TicTacToe::startGameWithComputer()
{
    EGameMode gameMode = EGameMode::Singleplayer;
    MainWindow* game = new MainWindow(gameMode);
    game->show();
    auto uiListener = std::make_shared<UIListener>(1, game->GetGame());
    game->GetGame()->AddListener(uiListener);
    hide();
}

void TicTacToe::startGameWithPlayer()
{
    EGameMode gameMode = EGameMode::Multiplayer;
    MainWindow* game = new MainWindow(gameMode);
    game->show();
    auto uiListener = std::make_shared<UIListener>(1, game->GetGame());
    game->GetGame()->AddListener(uiListener);
    hide();
}