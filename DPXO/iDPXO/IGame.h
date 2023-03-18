#pragma once
#include <array>
#include <cstdint>
#include <vector>
#include <memory>

//Enums
enum class EGameState {
	Playing,
	Win,
	Tie
};

enum class EMoveResult {
	Fail,
	Success
};

enum class EGameMode {
	Singleplayer,
	Multiplayer
};

//Typdefs
using Pos = std::pair<uint16_t, uint16_t>;
using BoardContent = std::array<std::array<char, 3>, 3>;
using EmptyPositions = std::vector<std::pair<uint16_t, uint16_t>>;
using IGamePtr = std::shared_ptr<class IGame>;

class IGame
{
public:
	//Static Methods
	static IGamePtr Produce();
	//Methods
	virtual EMoveResult MakeMove(Pos position, EGameMode gameMode) = 0;
	virtual BoardContent GetBoardContent() = 0;
	virtual EGameState GetState() = 0; 
	//int GetCurrentPlayer()

	//Destructor
	virtual ~IGame() = default;
};
