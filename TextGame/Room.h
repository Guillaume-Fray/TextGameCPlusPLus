//
// Created by DrMark on 10/2/2017, modified by 17008776
//


#ifndef TEXTADV_ROOM_H
#define TEXTADV_ROOM_H

#include <string>
#include <forward_list>
#include <list>
#include "GameObject.h"

using std::string;

/**
 * Represents a room (accessible location in the game).
 */
class Room {
public:
    /**
     * Short name used as a header.
     */
    const string* name;
    /**
     * Full description of the room.
     */
    const string* description;
    /**
     * Pointer to room that is north of this one.
     */
    Room* north;
    /**
     * Pointer to room that is south of this one.
     */
    Room* south;
    /**
     * Pointer to room that is east of this one.
     */
    Room* east;
    /**
     * Pointer to room that is west of this one.
     */
    Room* west;
public:
    /**
     * Constructs a new Room.
     * @param _name Name of the room.
     * @param _desc Description of the room.
     */
    Room(const string *_name, const string *_desc);

    /**
     * Removes a destroyed room from the global list if it's there.
     */
    ~Room();

    /**
     * Outputs the name and description of the room
     * in standard format.
     */
    void describe() const;

    /**
     * List storing all rooms that have been registered via addRoom().
     */
    static std::list<Room*> rooms;

    /**
     * List storing all objects present in the Room.
     */
     std::list<GameObject*> objectList;

    /**
     * Creates a new Room with the given parameters and registers it with the static list.
     * @param _name Name of the room.
     * @param _desc Description of the room.
     */
    static Room* addRoom(const string* _name, const string* _desc);

    /**
    * Adds an existing room to the static list.
    * @param room Pointer to the Room to add.
    */
    static Room* addRoom(Room* room);

    /**
    * Adds an existing object to the objectList.
    * @param obj Pointer to the GameObject to add.
    */
    GameObject* addObject(GameObject* object);

    /**
    * Removes an existing object from the objectList.
    * @param obj Pointer to the GameObject to remove.
    */
    GameObject* removeObject(GameObject* object);



    /**
    * Accessors and Mutators for the 4 "exits" properties of a Room.
    */
    Room* getNorth() const;
    void setNorth(Room* _north);

    Room* getSouth() const;
    void setSouth(Room* _south);

    Room* getEast() const;
    void setEast(Room* _east);

    Room* getWest() const;
    void setWest(Room* _west);

};

#endif //TEXTADV_ROOM_H
