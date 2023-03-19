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

	/// Constructs an object of type Game and wraps it in a std::shared_ptr to IGame
	/// \return a shared_ptr to IGame
	static IGamePtr Produce();
	//Methods

	/// For each type of game checks if the player can add a symbol on a position and if it's affirmative it adds it and returns the result
	/// \param position a position where the move must be made
	/// \param gameMode the type of game being played
	/// \returns Movement result that is fail or success
	virtual EMoveResult MakeMove(Pos position, EGameMode gameMode) = 0;

	/// Gets the matrix of the board
	/// \returns The matrix of the board
	virtual BoardContent GetBoardContent() = 0;

	/// Gets the state of the game ( playing, win, tie )
	/// \returns The state of the game ( playing, win, tie )
	virtual EGameState GetState() = 0;

	/// Tells the observer how the game ended
	virtual void GameOver() = 0;



	//Listeners

	/// Adds a new listener to the observer
	/// \param observer a pointer to IGameListener
	virtual void AddListener(IGameListenerPtr observer) = 0;

	/// Removes a listener from the observer
	/// \param observer a pointer to IGameListener
	virtual void RemoveListener(IGameListenerPtr observer) = 0;

	//Destructor
	virtual ~IGame() = default;
};
