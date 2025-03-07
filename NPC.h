/*
 * Author(s): Connor Krell, Daniel Lebedev
 * Description: NPC class represents helpful characters the player can interact with.
 */
#ifndef NPC_H
#define NPC_H
#include <string>
#include "Item.h"
#include "Player.h"
using namespace std;

class NPC {
private:
    // NPC member variables
    string questDescription;
    int requiredKills;
    Item* rewardItem;
    bool questCompleted = false;

public:
    // Function declarations
    NPC(string questDescription, int requiredKills, Item* rewardItem):
        questDescription(questDescription), requiredKills(requiredKills), rewardItem(rewardItem) {}
    void showQuest();
    void completeQuest(Player& player);

    // Getters & Setters
    int getRequiredKills() { return requiredKills; }
    void setRequiredKills(int requiredKills) { this->requiredKills = requiredKills; }
};

// Define NPCs
extern NPC QUEST_GIVER_1;
extern NPC QUEST_GIVER_2;
extern NPC QUEST_GIVER_3;

#endif // NPC_H
