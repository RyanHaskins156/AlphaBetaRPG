/*
 * Author(s): Xavier Bailey
 * Description: ...
 */
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using namespace std;

 // parent enemy class, each enemy will have name, health, damage, weapon, and ability
class Enemy {
protected:
    string name;
    int health;
    int damage;
    string weapon;
    string ability;
    int x, y;
public:
    Enemy(string n, int h, int d, string w, string a, int x, int y);

    virtual void attack(); // attack function
    virtual void specialAbility(); // special ability function

    // Getters & Setters
    string getName() const { return name; }
    int getHealth() const { return health; }
    void setHealth(int health) { this->health = health; }
    int getDamage() const { return damage; }
    string getWeapon() const { return weapon; }
    string getAbility() const { return ability; }
    int getX() const { return x; }
    int getY() const { return y; }
};

class GhostKnight : public Enemy { // GhostKnight - An undead knight haunting the dungeon, seeking revenge on those who disturb its eternal rest.
public:
    GhostKnight(int x, int y);
    void specialAbility() override;
};

class Skeleton : public Enemy { // Skeleton - A restless skeleton warrior, forever guarding the treasures of the dungeon.
public:
    Skeleton(int x, int y);
    void specialAbility() override;
};

class Goblin : public Enemy { // Goblin - A mischievous goblin looking to cause trouble and pain.
public:
    Goblin(int x, int y);
    void specialAbility() override;
};

class SwarmOfBats : public Enemy { // SwarmOfBats - A dark and sinister swarm of bats that spreads fear and chaos in the dungeon.
public:
    SwarmOfBats(int x, int y);
    void specialAbility() override;
};

class DarkMage : public Enemy { // DarkMage - A malicious mage whose dark magic drains the life force of any who cross its path.
public:
    DarkMage(int x, int y);
    void specialAbility() override;
};


extern GhostKnight GHOSTKNIGHT;
extern Skeleton SKELETON;
extern Goblin GOBLIN;
extern SwarmOfBats SWARMOFBATS;
extern DarkMage DARKMAGE;

#endif
