#pragma once
#include <array>
#include <cstdint>
#include <vector>
#include <memory>
#include "IGameListener.h"

//Enums

/*! The current state of the game */
enum class EGameState {
	Playing, /*!< Players are still placing symbols on the board */
	Win, /*!< The game finished and it's won by a player */
	Tie /*!< The game finished, but nobody won, there is draw */
};

/*! The current state of the game */
enum class EMoveResult {
	Fail,/*!< The move was made on a cell which is not empty */
	Success /*!< The move took place successfully */
};

/*! The game mode */
enum class EGameMode {
	Singleplayer, /*!< The user is playing against computer */
	Multiplayer /*!< The user has control over the placement of both symbols  */
};

/*! The way how computer chooses positions where to place its symbol */
enum class EStrategyType {
	Easy, /*!< User has high chances to win */
	Medium, /*!< User has lower chances to win */
	Difficult /*!< It is pretty hard for user to win */
};

/*! The symbols that is filling a cell at the moment */
enum class ECellState {
	Zero, /*!< This means the char '0' on the board */
	Cross, /*!< This means the char 'X' on the board */
	Empty /*!< The cell is empty */
};



//Typdefs

/** This is the data structure that holds the game board */
using BoardContent = std::array<std::array<char, 3>, 3>;

/** This is a container that holds only the cells that are still empty */
using EmptyPositions = std::vector<std::pair<int, int>>;

/** This is a shared pointer to an object of IGame type */
using IGamePtr = std::shared_ptr<class IGame>;

class IGame
{
public:
	//Static Methods

	/// \brief Constructs an object of type Game and wraps it in a std::shared_ptr to IGame
	/// \param strategyType the type of strategy that user chose to play 
	/// \return a shared_ptr to IGame
	static IGamePtr Produce(EStrategyType strategyType);
	//Methods

	/// \brief For each type of game checks if the player can add a symbol on a position and if it's affirmative it adds it and returns the result
	/// \param position a position where the move must be made
	/// \param gameMode the type of game being played
	/// \returns Movement result that is fail or success
	virtual EMoveResult MakeMove(Position position, EGameMode gameMode) = 0;

	/// \brief Gets the matrix of the board
	/// \returns The matrix of the board
	virtual BoardContent GetBoardContent() = 0;

	/// \brief Gets the state of the game ( playing, win, tie )
	/// \returns The state of the game ( playing, win, tie )
	virtual EGameState GetState() = 0;

	/// \brief Tells the observer how the game ended
	virtual void GameOver() = 0;


	//Listeners

	/// \brief Adds a new listener to the observer
	/// \param observer a weak_ptr to IGameListener
	virtual void AddListener(IGameListenerWeakPtr observer) = 0;

	/// \brief Removes a listener from the observer
	/// \param observer a weak_ptr to IGameListener
	virtual void RemoveListener(IGameListenerWeakPtr observer) = 0;

	//Destructor
	virtual ~IGame() = default;
};
