#pragma once
#include <array>
#include <cstdint>
#include <vector>
#include <memory>

enum class EGameState { // EGameState/EGameStatus
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

using Pos = std::pair<uint16_t, uint16_t>;
using IGamePtr = std::shared_ptr<class IGame>;

class IGame
{
	//Methods
public:
	static IGamePtr Produce();
	virtual EMoveResult MakeMove(Pos position, EGameMode gameMode) = 0;
	//virtual EGameState GameState() const = 0; 
	//int GetCurrentPlayer()
	virtual BoardContent GetBoardContent();

	//Destructor
	virtual ~IGame() = default;
};
