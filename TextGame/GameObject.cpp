//
// Created by 17008776.
//

#include "GameObject.h"
#include "Room.h"



/**
 * GameObject default constructor.
 * @param _name GameObject's name.
 * @param _desc GameObject's description.
 * @param _keyword GameObject's keyword.
 */
GameObject::GameObject(const string *_name, const string *_desc, const string *_keyword) :
        name(_name), description(_desc), keyword(_keyword) {};

/**
 * Remove destroyed object from the static list.
 */
GameObject::~GameObject() {
}

