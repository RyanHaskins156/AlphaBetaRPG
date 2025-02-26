/*
 * Author(s): Connor Krell, Daniel Lebedev
 * Description: ...
 */
#ifndef NPC_H
#define NPC_H
#include <string>
#include "Item.h"
#include "Player.h"
using namespace std;

class NPC {
private:
    // Quest requirements/info
    string questDescription;
    int requiredKills;
    Item* rewardItem;
    bool questCompleted = false;

public:
    NPC(string questDescription, int requiredKills, Item* rewardItem):
        questDescription(questDescription), requiredKills(requiredKills), rewardItem(rewardItem) {}
    void showQuest();
    void completeQuest(Player& player);
};

// Define NPCs
extern NPC QUEST_GIVER_1;
extern NPC QUEST_GIVER_2;
extern NPC QUEST_GIVER_3;

#endif // NPC_H
