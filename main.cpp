/*
 * 
 *
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include "utilities.hpp"
#include "engine.hpp"
#include "room.hpp"
#include "house.hpp"
#include "feature.hpp"

void printGameEnding();
/* TODO 
 * 	Make sure the GameStateconstructor deals with game saved files
 *
 *
 *
 *
 *
 */

int main()
{
	int GameClock=0;
	House *house = NULL;
	Room 	*currentRoom = NULL;
	GameState PlayerState("player"); 

	house = new House();
	currentRoom = house->buildHouse("Foyer");

	PlayerState.housePtr = house;
	house->printRooms(&PlayerState);
	house->printFeatures(&PlayerState);
	std::cout << "=============================================" << std::endl;
	std::cout << "\nTo move around use verbs like 'go', 'move', 'walk', etc" << std::endl;
	std::cout << "\nTo interact with objects in the room try words like 'use','take','move', etc" << std::endl;
	std::cout << "=============================================" << std::endl;

	currentRoom->Examine(&PlayerState);
	while ( currentRoom != NULL )
	{
		currentRoom = PlayerState.playerTurn(currentRoom);
		PlayerState.UpdateGameState(GameClock,currentRoom);
	}

	//house->printRooms(); // DEBUG
	printGameEnding();
	delete house;
	return 0;
}



void printGameEnding() {
	std::cout << "Game Over" << std::endl;
	
}
