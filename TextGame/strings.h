//
// Created by DrMark on 10/4/2017, modified by 17008776.
//

#ifndef TEXTADV_STRINGS_H
#define TEXTADV_STRINGS_H


#include <string>

const std::string r1name = "Room_1";
const std::string r1desc = "You are in Room 1; you don't know how you got there but at least you know you're in room 1."
                           " There's a small cylindrical structure made of stone in the center of this square-shaped"
                           " room. You move towards it and you can see a compass on top of it. You look around and notice"
                           " that there's a passage for each corresponding cardinal point.\n\n";




const std::string r1Nname = "Blue_Room";
const std::string r1Ndesc = "You are in the blue room. You know because it's blue. That's about all though. There's a "
                           "passage to the north, to the east, to the west and obviously to the south as you just came"
                           "from there.\n\n";

const std::string r1NNname = "Red_Room";
const std::string r1NNdesc = "You are in the red room.";
const std::string r1NWname = "Green Room";
const std::string r1NWdesc = "You are in the green room.";
const std::string r1NEname = "Yellow Room";
const std::string r1NEdesc = "You are in the yellow room.";

//the room south to this room is Room 1






const std::string r1Sname = "Spherical_Room";
const std::string r1Sdesc = "You are in the spherical room. You fell down to its center due to the curved floor."
                            "It appears that there are only 2 other passages in this room: one to the west and one "
                            "to the east\n\n";

const std::string r1SEname = "Cubic_Room";
const std::string r1SEdesc = "You are in the cubic room.";
const std::string r1SWname = "Pyramidal Room";
const std::string r1SWdesc = "You are in the pyramidal room.";

//the room north to this room is Room 1
// No passage to the south





const std::string r1Ename = "Dark_Room";
const std::string r1Edesc = "You can't see your feet or even your nose in here, you wander around to find an exit.";

const std::string r1ESname = "Light_Room";
const std::string r1ESdesc = "\"Despite all the light (and because of that), you can't see anything either in this "
                             "room. You're thinking that some sun glasses would be a nice thing to have here...";
const std::string r1ENname = "Middle_Room";
const std::string r1ENdesc = "You are in a pretty useless room. There is nothing in here, only one door on your left.";

//the room west to this room is Room 1
// No passage to the east






const std::string r1Wname = "Weird_Corridor";
const std::string r1Wdesc = "This is odd. The west passage didn't lead to a door but to a staircase followed by "
                            "a long and narrow corridor that leads to another room. The corridor is not very special "
                            "apart from a red door painted on one wall.\n\n";
const std::string r1WWname = "Strange_Room";
const std::string r1WWdesc = "Looks like the decorator had an obsession with keys and question marks... "
                             "You can see keys of all shapes and colours, and question marks painted everywhere in this"
                             " room. Seriously, what is it with this place?";
//the room east to this room is Room 1
// No passage to the north or to the south













const std::string bigKey_name = "big Key";
const std::string bigKey_desc = "This looks like an old metallic key. Probably to open a rusty door or a treasure "
                                "chest perhaps.";
const std::string bigKey_keyword = "bigKey";

const std::string flask_name = "basic flask";
const std::string flask_desc = "This is a flask that can contain one litre of water.";
const std::string flask_keyword = "flask";

const std::string rope_name = "rope";
const std::string rope_desc = "This is a 5 meter long rope.";
const std::string rope_keyword = "rope";

const std::string knife_name = "penknife";
const std::string knife_desc = "This is just a small knife. The blade seems to be damaged.";
const std::string knife_keyword = "penknife";

const std::string lighter_name = "lighter";
const std::string lighter_desc = "This is an antique oil lighter. The lighter seems full.";
const std::string lighter_keyword = "lighter";

const std::string cigarettes_name = "pack of cigarettes";
const std::string cigarettes_desc = "There are 5 cigarettes left in this pack.";
const std::string cigarettes_keyword = "cigarettes";

const std::string magnGlass_name = "magnifying glass";
const std::string magnGlass_desc = "Since you haven't got your glasses with you, this might be useful.";
const std::string magnGlass_keyword = "magnifying_glass";

const std::string apple_name = "apple";
const std::string apple_desc = "This is a Cripps Pink apple. For what you know, this is edible. You might need it when "
                               "your energy levels are low.";
const std::string apple_keyword = "apple";

const std::string lamp_name = "torch lamp";
const std::string lamp_desc = "This is a small torch lamp. It can be useful within these gloomy walls. It's got no"
                              "battery though.";
const std::string lamp_keyword = "lamp";

const std::string battery_name = "common battery";
const std::string battery_desc = "these are just a couple of AAA batteries. The kind you could use for a torch lamp for"
                                 "instance.";
const std::string battery_keyword = "battery";












const std::string badExit = "You can't go that way.";
const std::string badCommand = "I don't understand that.";


#endif //TEXTADV_STRINGS_H
