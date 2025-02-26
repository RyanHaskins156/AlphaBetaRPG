/*
 * Author(s): Connor Krell, Daniel Lebedev
 * Description: Description: Defines NPC functions.
 */
#include "NPC.h"

// Displays quest or tells user they've completed it already
void NPC::showQuest() {
    if (questCompleted) {
        cout << "You have already completed this quest.\n";
    } else {
        cout << questDescription << "\n";
        cout << "Kill " << requiredKills << " enemies to receive: " << rewardItem->getName() << ".\n";
    }
}

// Checks if player met quest requirements and rewards player
void NPC::completeQuest(Player& player) {
    if (!questCompleted && player.getKills() >= requiredKills) {
        cout << "Congratulations! You have completed the quest and received: " << rewardItem->getName() << "!\n";
        player.addItem(rewardItem);
        questCompleted = true;
    } else {
        showQuest();
    }
}

// Instantiate NPCs to be used in game.
NPC QUEST_GIVER_1("Defeat 1 Enemy", 1, &LESSER_HEALTH);
NPC QUEST_GIVER_2("Defeat 5 Enemies", 5, &GREATER_HEALTH);
NPC QUEST_GIVER_3("Defeat 10 Enemies", 10, &EPIC_HEALTH);
