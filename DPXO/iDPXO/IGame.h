#pragma once
#include <array>
#include <cstdint>
#include <vector>
#include <memory>
#include "IGameListener.h"

//Enums
enum class EMoveResult {
	Fail,
	Success
};

enum class EGameMode {
	Singleplayer,
	Multiplayer
};

//Typdefs
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
	virtual void GameOver() = 0;

	//Listeners
	virtual void AddListener(IGameListenerPtr observer) = 0;
	virtual void RemoveListener(IGameListener* observer) = 0;

	//Destructor
	virtual ~IGame() = default;
};
