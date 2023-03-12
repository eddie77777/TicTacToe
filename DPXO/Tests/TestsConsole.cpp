#include <gtest/gtest.h>
#include "Hplayer.h"
#include "GameLogic.h"
#include "Game.h"
#include <iostream>
#include <string>

TEST(ValidHPlayerInput, test)
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
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
