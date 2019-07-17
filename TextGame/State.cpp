//
// Created by DrMark on 10/2/2017 modified by 17008776.
//

#include "State.h"

/**
 * Current state of the game.
 */


/**
 * Player's inventory.
 */
std::list<GameObject*> State :: inventory;

/**
 * Display the description of the room the player is in. */
void State::announceLoc() const {
    this->currentRoom->describe();
}

/**
 * Constructor.
 * @param startRoom Pointer to the room to start in.
 */
State::State(Room *startRoom) : currentRoom(startRoom) {};

/**
 * Move to a specified room and print its description.
 * @param target Pointer to the room to move to.
 */
void State::goTo(Room *target) {
    this->currentRoom = target;
    this->announceLoc();
}

/**
 * Return a pointer to the current room.
 * @return Pointer to the current room.
 */
Room* State::getCurrentRoom() {
    return this->currentRoom;
}


/**
* Adds an object to the inventory.
* @param obj Pointer to the GameObject to add.
*/
GameObject* State::addToInventory(GameObject* object) {
    State::inventory.push_back(object);
}


/**
* Removes an object from the inventory.
* @param obj Pointer to the GameObject to remove.
*/
GameObject* State::dropObject(GameObject* object) {
    inventory.remove(object);
}