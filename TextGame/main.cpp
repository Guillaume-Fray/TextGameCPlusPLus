//
// Created by by 17008776 on 25/10/2018.
//

#include <iostream>
#include <iomanip>
#include <memory>
#include <iterator>
#include <cstdio>
#include <forward_list>
#include <fstream>
#include <sstream>
#include "Room.h"
#include "wordwrap.h"
#include "State.h"
#include "strings.h"

using namespace std;
using std::string;
using std::unique_ptr;

string commandBuffer;
State *currentState;
bool restoreValue = false;


/**
 * Used to open a different file according to the operation (start from the saved file or from the start)
 */
void restore(bool restore){
    restoreValue = restore;
}

/**
 * Print out the command prompt then read a command into the provided string buffer.
 * @param buffer Pointer to the string buffer to use.
 */
void inputCommand(string *buffer) {
    buffer->clear();
    std::cout << "> ";
    std::getline(std::cin, *buffer);
}

/**
 * Sets up the map.
 */
void initRoomsAndState() {
    // builds rooms
    auto *r1 = new Room(&r1name, &r1desc);

    auto *r1S = new Room(&r1Sname, &r1Sdesc);
    auto *r1SE = new Room(&r1SEname, &r1SEdesc);
    auto *r1SW = new Room(&r1SWname, &r1SWdesc);

    auto *r1E = new Room(&r1Ename, &r1Edesc);
    auto *r1EN = new Room(&r1ENname, &r1ENdesc);
    auto *r1ES = new Room(&r1ESname, &r1ESdesc);

    auto *r1W = new Room(&r1Wname, &r1Wdesc);
    auto *r1WW = new Room(&r1WWname, &r1WWdesc);

    auto *r1N = new Room(&r1Nname, &r1Ndesc);
    auto *r1NN = new Room(&r1NNname, &r1NNdesc);
    auto *r1NW = new Room(&r1NWname, &r1NWdesc);
    auto *r1NE = new Room(&r1NEname, &r1NEdesc);


    Room::addRoom(r1);

    Room::addRoom(r1N);
    r1->setNorth(r1N);
    Room::addRoom(r1NN);
    r1N->setNorth(r1NN);
    r1NN->setSouth(r1N);
    Room::addRoom(r1NE);
    r1N->setEast(r1NE);
    r1NE->setWest(r1N);
    Room::addRoom(r1NW);
    r1N->setWest(r1NW);
    r1NW->setEast(r1N);
    r1N->setSouth(r1);

    Room::addRoom(r1S);
    r1->setSouth(r1S);
    Room::addRoom(r1SE);
    r1S->setEast(r1SE);
    r1SE->setWest(r1S);
    Room::addRoom(r1SW);
    r1S->setWest(r1SW);
    r1SW->setEast(r1S);
    r1S->setNorth(r1);

    Room::addRoom(r1E);
    r1->setEast(r1E);
    Room::addRoom(r1EN);
    r1E->setNorth(r1EN);
    r1EN->setSouth(r1E);
    Room::addRoom(r1ES);
    r1E->setSouth(r1ES);
    r1ES->setNorth(r1E);
    r1E->setWest(r1);

    Room::addRoom(r1W);
    r1->setWest(r1W);
    Room::addRoom(r1WW);
    r1W->setWest(r1WW);
    r1WW->setEast(r1W);
    r1W->setEast(r1);

/**
* Sets up the game state.
*/

    // builds objects
    auto *bigKey = new GameObject(&bigKey_name, &bigKey_desc, &bigKey_keyword);
    auto *flask = new GameObject(&flask_name, &flask_desc, &flask_keyword);
    auto *rope = new GameObject(&rope_name, &rope_desc, &rope_keyword);
    auto *knife = new GameObject(&knife_name, &knife_desc, &knife_keyword);
    auto *lighter = new GameObject(&lighter_name, &lighter_desc, &lighter_keyword);
    auto *cigarettes = new GameObject(&cigarettes_name, &cigarettes_desc, &cigarettes_keyword);
    auto *magnGlass = new GameObject(&magnGlass_name, &magnGlass_desc, &magnGlass_keyword);
    auto *apple = new GameObject(&apple_name, &apple_desc, &apple_keyword);
    auto *lamp = new GameObject(&lamp_name, &lamp_desc, &lamp_keyword);
    auto *battery = new GameObject(&battery_name, &battery_desc, &battery_keyword);



    // contains all objects of the game
    GameObject *allExistingObjects[10] = {bigKey, flask, rope, knife, lighter,
                                          cigarettes, magnGlass, apple, lamp, battery};


    // check which objects are in the inventory.txt file and copy them into the inventory list
    ifstream inventoryReader;
    if (restoreValue){
        inventoryReader.open("startinginventory.txt");
    }
    else{
        inventoryReader.open("inventory.txt");
    }
    if (inventoryReader.is_open()) {
        string line;
        while (!inventoryReader.eof()) {
            getline(inventoryReader, line);
            for (GameObject *obj : allExistingObjects) {
                if (line == (*obj->keyword))
                    State::addToInventory(obj);
            }
        }
    } else {
        cout << "Error: inventory file not open" << endl;
    }
    inventoryReader.close();



    // check for each room which objects are in the roomobjects.txt file and copy them into the corresponding room list.
    ifstream roomReader;
    if (restoreValue){
        roomReader.open("startingroomsobjects.txt");
    }
    else{
        roomReader.open("roomobjects.txt");
    }
    if (roomReader.is_open()) {
        string word1;
        string word2;
        string line;
        string str;
        while (!roomReader.eof()) {
            getline(roomReader, line);
            stringstream ss(line);
            getline(ss, str, ' ');
            word1 = str;
            for (Room *room : Room::rooms) {
                if (word1 == (*room->name)) {
                    getline(ss, str, ' ');
                    word2 = str;
                    for (GameObject *obj : allExistingObjects) {
                        if (word2 == (*obj->keyword)) {
                            room->addObject(obj);
                        }
                    }
                }
            }
        }
    }
    else {
        cout << "Error: roomobjects file not open" << endl;
    }
    roomReader.close();


    // check in which room the player was before quiting the game. Set the player in room 1 if the saving file's empty.
    ifstream startRoomReader;
    if (restoreValue){
        currentState = new State(r1);
    }
    else{
        startRoomReader.open("currentroom.txt");
        if (startRoomReader.is_open()) {
            string line;
            getline(startRoomReader, line);
            if (!line.empty()) {
                for (Room *room : Room::rooms) {
                    if (line == (*room->name)){
                        currentState = new State(room);
                    }
                }
            }
            else{
                currentState = new State(r1);
            }
        } else {
            cout << "Error: inventory file not open" << endl;
        }
        startRoomReader.close();
    }

}





/**
 * The main game loop.
 */
void gameLoop() {
    bool gameOver=false;
    while (!gameOver) {
        /* Ask for a command. */
        bool commandOk = false;
        cout<<"\nWhat would you like to do?\n"<<endl;
        inputCommand(&commandBuffer);
        /* The first word is the text before the first space */
        auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));
        string firstWord = commandBuffer.substr(0,endOfVerb);
        string secondWord = ""; // initialise the second word to an empty string

        // if there is more than one word  (built as if the whole input is larger than the first word before a space)
        // then 2nd word = what starts after the space to the end
        if (commandBuffer.size() > firstWord.length()+1) {
            secondWord = commandBuffer.substr(firstWord.length() + 1, commandBuffer.size() - firstWord.length());
        }

        /* Compare the first or the second word of the command if there is one */
        /* Command to go north. */
        if ((commandBuffer.compare(0, endOfVerb,"north") == 0) || (secondWord == "north")) {
            commandOk = true; /* Confirm command has been handled */
            /* See if there's a north exit */
            Room *northRoom = currentState->getCurrentRoom()->getNorth();
            if (northRoom == nullptr) { /* there isn't */
                wrapOut(&badExit);      /* Output the "can't go there" message */
                wrapEndPara();
            } else {                    /* There is */
                currentState->goTo(northRoom); /* Update state to that room - this will also describe it */
            }
        }

        /* Command to go south. */
        if ((commandBuffer.compare(0,endOfVerb,"south") == 0) || (secondWord == "south")) {
            commandOk = true; /* Confirm command has been handled */
            /* See if there's a south exit */
            Room *southRoom = currentState->getCurrentRoom()->getSouth();
            if (southRoom == nullptr) { /* there isn't */
                wrapOut(&badExit);      /* Output the "can't go there" message */
                wrapEndPara();
            } else {                    /* There is */
                currentState->goTo(southRoom); /* Update state to that room - this will also describe it */
            }
        }

        /* Command to go east. */
        if ((commandBuffer.compare(0,endOfVerb,"east") == 0) || (secondWord == "east")) {
            commandOk = true; /* Confirm command has been handled */
            /* See if there's an east exit */
            Room *eastRoom = currentState->getCurrentRoom()->getEast();
            if (eastRoom == nullptr) { /* there isn't */
                wrapOut(&badExit);      /* Output the "can't go there" message */
                wrapEndPara();
            } else {                    /* There is */
                currentState->goTo(eastRoom); /* Update state to that room - this will also describe it */
            }
        }

        /* Command to go west. */
        if ((commandBuffer.compare(0,endOfVerb,"west") == 0) || (secondWord == "west")) {
            commandOk = true; /* Confirm command has been handled */
            /* See if there's a west exit */
            Room *westRoom = currentState->getCurrentRoom()->getWest();
            if (westRoom == nullptr) { /* there isn't */
                wrapOut(&badExit);      /* Output the "can't go there" message */
                wrapEndPara();
            } else {                    /* There is */
                currentState->goTo(westRoom); /* Update state to that room - this will also describe it */
            }
        }

        /* Command "search" : to search for an object */
        if ((commandBuffer.compare(0,endOfVerb,"search") == 0)) {
            commandOk = true; /* Confirm command has been handled */
            bool found = false;
            for (GameObject *obj : State::inventory){
                if(secondWord == *obj->keyword) {
                    cout <<"You've got a " << *obj->name << " in your inventory.\n" << endl;
                    found = true;
                    break;
                }
            }
            for (GameObject *obj : currentState->getCurrentRoom()->objectList){
                if(secondWord == *obj->keyword) {
                    cout <<"There is a "<< *obj->name << " in this room.\n" << endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout <<"There is no "<< secondWord << " in this room or in your inventory\n" << endl;
            }
        }


        /* Command "get" : to pick up an object present in the current room and place it into the inventory */
        if ((commandBuffer.compare(0,endOfVerb,"get") == 0)) {
            commandOk = true; /* Confirm command has been handled */
            bool found = false;
            for (GameObject *obj : currentState->getCurrentRoom()->objectList) {
                if (secondWord == *obj->keyword) {
                    State::addToInventory(obj);
                    currentState->getCurrentRoom()->removeObject(obj);
                    cout << "You now have a " << *obj->name << " in your inventory.\n" << endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "There is no " << secondWord << " in this room.\n" << endl;
            }
        }

        /* Command "drop" : to remove an object from the inventory and leave it into the current room. */
        if ((commandBuffer.compare(0,endOfVerb,"drop") == 0)) {
            commandOk = true; /* Confirm command has been handled */
            bool found = false;
            for (GameObject *obj : State::inventory) {
                if (secondWord == *obj->keyword) {
                    currentState->getCurrentRoom()->addObject(obj);
                    cout << "You just got rid of a " << *obj->name << "\n" << endl;
                    State::dropObject(obj);
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "You have no " << secondWord << " in your inventory.\n" << endl;
            }
        }

        /* Command "inventory" : to print out the short names of all objects present in the inventory */
        if ((commandBuffer.compare(0,endOfVerb,"inventory") == 0)) {
            commandOk = true; /* Confirm command has been handled */
            cout << "Your inventory contains the following objects:\n" << endl;
            for (GameObject *obj : State::inventory) {
                cout << *obj->name << endl;
            }
        }

        /* Command "examine" : to print out the long description of an object */
        if ((commandBuffer.compare(0,endOfVerb,"examine") == 0)) {
            commandOk = true; /* Confirm command has been handled */
            bool found = false;
            for (GameObject *obj : State::inventory) {
                if (secondWord == *obj->keyword) {
                    cout << *obj->description << "\n" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {   // to avoid examining twice the same object if present in the room and in the inventory.
                for (GameObject *obj : currentState->getCurrentRoom()->objectList) {
                    if (secondWord == *obj->keyword) {
                        cout << *obj->description << "\n" << endl;
                        found = true;
                        break;
                    }
                }
            }
            if(!found){
                cout <<"There is no "<< secondWord << " in this room or in your inventory\n" << endl;
            }
        }

        /* Save command */
        if ((commandBuffer.compare(0,endOfVerb,"save") == 0)) {
            commandOk = true;
            ofstream writer;
            writer.open("inventory.txt");
            if(writer.is_open()){
                for (GameObject *obj : State::inventory){
                    writer<<*obj->keyword<< endl;
                }
            }
            else{
                cout<<"Error: inventory file not open"<<endl;
            }
            writer.close();

            ofstream writer2;
            writer2.open("roomobjects.txt");
            if(writer2.is_open()){
                for (Room *r : Room::rooms){
                    for (GameObject *obj : r->objectList){
                        writer2<<*r->name<<" "<< *obj->keyword<< endl;
                    }
                }
            }
            else{
                cout<<"Error: roomobjects file not open"<<endl;
            }
            writer2.close();

            ofstream writer3;
            writer3.open("currentroom.txt");
            if(writer3.is_open()){
                writer3<<*currentState->getCurrentRoom()->name<<endl;
            }
            else{
                cout<<"Error: currentroom file not open"<<endl;
            }
            writer3.close();
        }


        /* Restore command */
        // "Are you sure you'd like to start from the beginning? You're progress will be lost.   Y/N >>> "
        if ((commandBuffer.compare(0,endOfVerb,"restore") == 0)) {
            commandOk = true;
            restore(true);
            ofstream writer,writer2;
            writer.open("roomobjects.txt");
            writer<<""<<endl;
            writer.close();
            writer2.open("inventory.txt");
            writer2<<""<<endl;
            writer2.close();
            State::inventory.clear();
            for (Room *r : Room::rooms) {
                r->objectList.clear();
            }
            for (auto it = Room::rooms.begin(); it != Room::rooms.end(); ) {
                it = Room::rooms.erase(it);
                ++it;
            }
            for (auto it = Room::rooms.begin(); it != Room::rooms.end(); ) {
                it = Room::rooms.erase(it);
                ++it;
            }
            initWordWrap();
            initRoomsAndState();
            currentState->announceLoc();
            gameLoop();
        }


        /* Quit command */
        if ((commandBuffer.compare(0,endOfVerb,"quit") == 0)) {
            commandOk = true;
            gameOver = true;
        }

        /* If commandOk hasn't been set, command wasn't understood, display error message */
        if(!commandOk) {
            wrapOut(&badCommand);
            wrapEndPara();
        }
    }
}


int main() {
    restore(false);
    initWordWrap();
    initRoomsAndState();
    currentState->announceLoc();
    gameLoop();
    return 0;
}