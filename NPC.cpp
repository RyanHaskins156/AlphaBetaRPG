/*
 * Author(s): Connor Krell, Daniel Lebedev
 * Description: Description: Defines NPC functions.
 */
#include "NPC.h"

// Handles interaction with player
void NPC::NPCDialog(Player& player) {
    string selection;
    cout << dialog << endl;
    while (true) {
        cout << "What would you like to do?" << endl;
        cout << "1 - Buy Item" << endl;
        cout << "2 - Sell Item" << endl;
        cout << "3 - View Quest" << endl;
        cout << "4 - Exit Dialog" << endl;

        cin >> selection;

        // UNFINISHED
        if (selection == "1") {
            cout << "Buying..." << endl;
            break;
        // UNFINISHED
        } else if (selection == "2") {
            cout << "Selling..." << endl;
            break;
        } else if (selection == "3") {
            completeQuest(player);
        } else if (selection == "4") {
            break;
        } else {
            cout << "Invalid selection! Try again!" << endl;
        }
    }
}

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
NPC QUEST_GIVER_1("John Quest", "Welcome to the game. Your goal is to defeat all enemies before finding the exit.", "Defeat 1 Enemy", 1, &LESSER_HEALTH, 1, 3);

