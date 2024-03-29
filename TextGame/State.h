//
// Created by DrMark on 10/2/2017, modified by 17008776.
//

#ifndef TEXTADV_STATE_H
#define TEXTADV_STATE_H


#include "Room.h"
#include "GameObject.h"

class State {
    Room *currentRoom;
public:
    explicit State(Room *startRoom);
    void goTo(Room *target);
    void announceLoc() const;
    Room* getCurrentRoom();
    static GameObject* addToInventory(GameObject* object);
    static GameObject* dropObject(GameObject* object);

    /**
    * List storing all objects present in the player's inventory.
    */
    static std::list<GameObject*> inventory;
};


#endif //TEXTADV_STATE_H
