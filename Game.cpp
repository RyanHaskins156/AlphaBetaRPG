/*
 * Author(s): Daniel Lebedev
 * Description: Handles game logic.
 */

#include <iostream>
#include <string>
#include "Player.h"
#include "NPC.h"

using namespace std;

class Game {
public:

    // UNFINISHED. NEEDS TO LOOP UNTIL GAME OVER (when currHealth = 0 or game is beat)
    // Will also need to take in a param representing current room
    void gameLoop(Player& player) {
        string selection;

        while (true) {
            cout << "What would you like to do next:" << endl;
            cout << "1 - Open Map" << endl;
            cout << "2 - Open Inventory" << endl;
            cout << "3 - Move rooms" << endl;

            // If user is in room with NPC, option to speak to NPC
            // Uncommented for testing
            cout << "4 - Talk to NPC" << endl;

            // If user is in room with Enemy, Option to flee or fight replaces move rooms
            // cout << "3 - Flee" << endl;
            // cout << "4 - Fight" << endl;

            cin >> selection;
            if (selection == "1") {
                cout << "Opening Map..." << endl;
                break;
            } else if (selection == "2") {
                player.displayInventory();
                break;
            } else if (selection == "3") {
                cout << "Moving..." << endl;
                break;

            // If user is in room with NPC, option to speak to NPC
            // Uncommented for testing
            } else if (selection == "4") {
                NPCDialog(QUEST_GIVER_1, player);
                break;
            } else {
                cout << "Invalid selection! Try again!" << endl;
            }
        }
    }

    void NPCDialog(NPC& npc, Player& player) {
        string selection;
        while (true) {
            cout << "Hello! What do you need?" << endl;
            cout << "1 - Buy Item" << endl;
            cout << "2 - Sell Item" << endl;
            cout << "3 - View Quest" << endl;
            cin >> selection;

            if (selection == "1") {
                cout << "Buying..." << endl;
                break;
            } else if (selection == "2") {
                cout << "Selling..." << endl;
                break;
            } else if (selection == "3") {

                npc.completeQuest(player);
                break;
            } else {
                cout << "Invalid selection! Try again!" << endl;
            }
        }
    }

    // Runs when game starts, creates player with selected info
    Player startGame() {
        string name, classSelection;
        PlayerClass playerClass;
        Item* starterWeapon;

        cout << "Welcome! Please enter your desired name: " << endl;
        cin >> name;

        // Loop until valid input
        while (true) {
            cout << "Please select your desired class: " << endl;
            cout << "1 - Warrior" << endl;
            cout << "2 - Mage" << endl;
            cout << "3 - Rogue" << endl;
            cin >> classSelection;

            // Set class to warrior and give player club
            if (classSelection == "1") {
                starterWeapon = &CLUB;
                Player player(name, WARRIOR);
                player.addItem(starterWeapon);
                return player;
            // Set class to mage and give player staff
            } else if (classSelection == "2") {
                starterWeapon = &STAFF;
                Player player(name, MAGE);
                player.addItem(starterWeapon);
                return player;
            // Set class to rogue and give player dagger
            } else if (classSelection == "3") {
                starterWeapon = &DAGGER;
                Player player(name, ROGUE);
                player.addItem(starterWeapon);
                return player;
            // Handle invalid input
            } else {
                cout << "Invalid selection! Try again!" << endl;
            }
        }
    }

};
