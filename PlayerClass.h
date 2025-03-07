/*
 * Author(s): Daniel Lebedev
 * Description: Struct defines viable classes and their stats.
 */
#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <string>

using namespace std;

struct PlayerClass {
    // PlayerClass member variables
    string className;
    int maxHp;
};

// Declare viable classes
extern const PlayerClass WARRIOR;
extern const PlayerClass MAGE;
extern const PlayerClass ROGUE;

#endif // PLAYERCLASS_H
