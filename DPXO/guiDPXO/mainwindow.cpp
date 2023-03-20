#include "mainwindow.h"
#include "QMessageBox"
#include "QVBoxLayout"

MainWindow::MainWindow(EGameMode gameMode, QWidget* parent)
    : QMainWindow(parent), m_gameMode(gameMode)
{
    // Create game board
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            buttons[row][col] = new QPushButton("", this);
            buttons[row][col]->setProperty("row", row);
            buttons[row][col]->setProperty("col", col);
            buttons[row][col]->setFixedSize(50, 50);
            connect(buttons[row][col], &QPushButton::clicked, this, &MainWindow::HandleButton);
        }
    }
    // Create layout and add widgets
    QGridLayout* layout = new QGridLayout;
    QWidget* widget = new QWidget(this);
    widget->setLayout(layout);
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            layout->addWidget(buttons[row][col], row, col);
        }
    }
    // Set the layout on the central widget of the main window
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    // Set the initial size of the main window to 300x300
    setFixedSize(300, 300);
    m_game = IGame::Produce();
}

MainWindow::~MainWindow()
{
}

void MainWindow::HandleButton()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int row = button->property("row").toInt();
    int col = button->property("col").toInt();
    m_game->MakeMove({ row, col }, m_gameMode);
    BoardContent boardContent = m_game->GetBoardContent();
    char value = boardContent[row][col];
    QString buttonText(value);
    button->setText(buttonText);
    button->setEnabled(false);
    if (m_game->GetState() != EGameState::Playing)
        m_game->GameOver();

}
 
IGamePtr MainWindow::GetGame()
{
    return m_game;
}