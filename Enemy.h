/*
 * Author(s): Xavier Bailey
 * Description: ...
 */
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using namespace std;

class Enemy { // parent enemy class, each enemy will have name, health, damage, weapon, and ability
public:
    string name;
    int health;
    int damage;
    string weapon;
    string ability;

    Enemy(string n, int h, int d, string w, string a);

    virtual void attack(); // attack function
    virtual void specialAbility(); // special ability function
};

class GhostKnight : public Enemy { // GhostKnight - An undead knight haunting the dungeon, seeking revenge on those who disturb its eternal rest.
public:
    GhostKnight();
    void specialAbility() override;
};

class Skeleton : public Enemy { // Skeleton - A restless skeleton warrior, forever guarding the treasures of the dungeon.
public:
    Skeleton();
    void specialAbility() override;
};

class Goblin : public Enemy { // Goblin - A mischievous goblin looking to cause trouble and pain.
public:
    Goblin();
    void specialAbility() override;
};

class SwarmOfBats : public Enemy { // SwarmOfBats - A dark and sinister swarm of bats that spreads fear and chaos in the dungeon.
public:
    SwarmOfBats();
    void specialAbility() override;
};

class DarkMage : public Enemy { // DarkMage - A malicious mage whose dark magic drains the life force of any who cross its path.
public:
    DarkMage();
    void specialAbility() override;
};


extern GhostKnight GHOSTKNIGHT;
extern Skeleton SKELETON;
extern Goblin GOBLIN;
extern SwarmOfBats SWARMOFBATS;
extern DarkMage DARKMAGE;

#endif
