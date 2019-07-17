//
// Created by 17008776.
//

#ifndef TEXTADV_GAMEOBJECT_H
#define TEXTADV_GAMEOBJECT_H

#include <string>
#include <forward_list>
#include <list>

using std::string;



/**
 * Represents an object that can be picked up or put down by the player.
 */
class GameObject {
public:
    /**
    * Short name used as a header.
    */
    const string* name;
    /**
     * Full description of the object.
     */
    const string* description;
    /**
    * Object's keyword for the player to use when typing commands.
    */
    const string* keyword;




public:
    /**
     * Constructs a new GameObject.
     * @param _name Name of the object.
     * @param _desc Description of the object.
     * @param _keyword Keyword of the object.
     */
    GameObject(const string *_name, const string *_desc, const string *_keyword);

    /**
     * Removes a destroyed GameObject from the global list if it's there.
     */
    ~GameObject();


};


#endif //TEXTADV_GAMEOBJECT_H
