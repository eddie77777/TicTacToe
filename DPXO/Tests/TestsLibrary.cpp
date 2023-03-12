#include <gtest/gtest.h>
#include "IPlayer.h"
#include <iostream>
#include <string>

/*TEST(ValidHPlayerInput, test)
{
    //GameLogic game;
    std::string lineInput("0");
    std::string columnInput("0");
    std::istringstream inputStream(lineInput);
    std::istringstream inputStream1(columnInput);
    //HPlayer player;
    //game.GetGame();
    Game game;
    game.GameState();

    EXPECT_EQ(0,0);
}*/

TEST(TestUpdate, Board)
{
    Board board;
    const std::pair<uint16_t, uint16_t> pos = { 1,1 };
    const char symbol = 'X';
    board.UpdateBoard(pos, symbol);
    EXPECT_EQ(board.GetMatrix()[1][1],symbol);
}

TEST(TestGetEmptyPosition,Board)
{
    Board board;
    std::pair<uint16_t, uint16_t> pos = { 1,1 };
    const char symbol = 'X';
    board.UpdateBoard(pos, symbol);
    for (uint16_t i = 0; i < board.GetEmptyPositions().size(); i++)
        EXPECT_NE(pos, board.GetEmptyPositions()[i]);
       
}

TEST(TestCheckIfAddOnNonValidPos,Game)
{
    Game game;
    std::pair<uint16_t, uint16_t> pos = { 1,1 };
    const char symbol = 'X';
    game.SetContentOnPos(pos, symbol);
    EXPECT_EQ(false, game.CheckIfAddOnPos(pos));
}

TEST(TestCheckIfAddOnValidPos, Game)
{
    Game game;
    std::pair<uint16_t, uint16_t> pos = { 1,1 };
    const char symbol = 'X';
    game.SetContentOnPos(pos, symbol);
    pos = { 0,1 };
    EXPECT_EQ(true, game.CheckIfAddOnPos(pos));
}

TEST(GetARandomEmptyPos, Game)
{
    std::pair<uint16_t, uint16_t> pos, pos1 = { 0,0 }, pos2 = {0,1};
    const char symbol = 'X';
    Game game;
    game.SetContentOnPos({ 0,2 }, symbol);
    for (uint16_t i = 1; i < 3; ++i)
        for (uint16_t j = 0; j < 3; ++j)
            game.SetContentOnPos({ i,j }, symbol);

    pos = game.GetARandomEmptyPos();
    EXPECT_TRUE( pos == pos1 || pos == pos2);
}

TEST(GameStateWinRow, Game)
{
    const char symbol = 'X';
    Game game;
    for (uint16_t i = 0; i < 3; ++i)
        game.SetContentOnPos({ 0,i }, symbol);

    EXPECT_EQ(game.GameState(),BoardState::Win);
}

TEST(GameStateWinColumn, Game)
{
    const char symbol = 'X';
    Game game;
    for (uint16_t i = 0; i < 3; ++i)
        game.SetContentOnPos({ i,0 }, symbol);

    EXPECT_EQ(game.GameState(), BoardState::Win);
}

TEST(GameStateWinPrincipalDiagonal, Game)
{
    const char symbol = 'X';
    Game game;
    for (uint16_t i = 0; i < 3; ++i)
        game.SetContentOnPos({ i,i }, symbol);

    EXPECT_EQ(game.GameState(), BoardState::Win);
}

TEST(GameStateWinSecondarylDiagonal, Game)
{
    const char symbol = 'X';
    Game game;
    for (uint16_t i = 0; i < 3; ++i)
        game.SetContentOnPos({ i,2 - i }, symbol);

    EXPECT_EQ(game.GameState(), BoardState::Win);
}


TEST(GameStateTie, Game)
{
    const char symbol1 = 'X';
    const char symbol2 = '0';
    Game game;
    game.SetContentOnPos({ 0,0 }, symbol1);
    game.SetContentOnPos({ 0,1 }, symbol1);
    game.SetContentOnPos({ 0,2 }, symbol2);
    game.SetContentOnPos({ 1,0 }, symbol2);
    game.SetContentOnPos({ 1,1 }, symbol2);
    game.SetContentOnPos({ 1,2 }, symbol1);
    game.SetContentOnPos({ 2,0 }, symbol1);
    game.SetContentOnPos({ 2,1 }, symbol2);
    game.SetContentOnPos({ 2,2 }, symbol1);

    EXPECT_EQ(game.GameState(), BoardState::Tie);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
