/*
 * Author(s): Daniel Lebedev
 * Description: Represents the player character. Has name, health, class, and inventory.
 */
#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerClass.h"
#include "Item.h"
#include <vector>
using namespace std;

class Player {
private:
    // Player member variables
    string name;
    const PlayerClass& playerClass;
    int currHealth;
    vector<pair<Item*, int>> inventory;
    int kills = 0;
public:
    // Currhealth determined by class' max health
    Player(string name, const PlayerClass& playerClass):
        name(name), playerClass(playerClass), currHealth(playerClass.maxHp) {}

    // Function declarations
    void printPlayer();
    void addItem(Item* item);
    void removeItem(Item* item);
    void useItem(int index);
    void displayInventory();

    // Getters & Setters
    string getName() { return name; }
    PlayerClass getPlayerClass() { return playerClass; }
    int getCurrHealth() { return currHealth; }
    void setCurrHealth(int currHealth) { this->currHealth = currHealth; }
    int getKills() { return kills; }
    void setKills(int kills) { this->kills = kills; }
};

#endif // PLAYER_H
