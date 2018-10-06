#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <string>
#include "room.hpp"

class House
{
	private:
		std::map<std::string,Room *> houseMap;   // this is a map of the house... room is key, holds the room pointer

	public:
		House(); // constructor
		~House();	// destructor
		bool buildHouse(std::string);
		bool hasRoom(std::string);   			// returns true if room ("Foyer" for instance) is found in the houseMap
		Room *getRoomPtr(std::string);      // retruns the ptr of the Room object for the requested room.
};

#endif