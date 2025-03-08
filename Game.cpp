/*
 * Author(s): Daniel Lebedev and Ryan Haskins
 * Description: Handles game logic.
 */

#include <iostream>
#include <string>
#include "Player.h"
#include "NPC.h"
#include "Map.h"
#include "enemy.h"
using namespace std;

class Game {
public:

    // UNFINISHED. NEEDS TO LOOP UNTIL GAME OVER (when currHealth = 0 or game is beat)
    // Will also need to take in a param representing current room
    void gameLoop(Player& player, Map& map) {
        string selection;

        while (true) {
            cout << "What would you like to do next:" << endl;
            cout << "1 - Open Map" << endl;
            cout << "2 - Open Inventory" << endl;
            cout << "3 - Move rooms" << endl;

            // If user is in room with NPC, option to speak to NPC
            // cout << "4 - Talk to NPC" << endl;

            // If user is in room with Enemy, Option to flee or fight replaces move rooms
            // cout << "3 - Flee" << endl;
            // cout << "4 - Fight" << endl;

            cin >> selection;
            if (selection == "1") {
                cout << "Opening Map..." << endl;
                map.renderMap();
            }
            else if (selection == "2") {
                player.displayInventory();
            }
            else if (selection == "3") {
                playerMvmt(map, player);
            }
            else {
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
            }
            else if (classSelection == "2") {
                starterWeapon = &STAFF;
                Player player(name, MAGE);
                player.addItem(starterWeapon);
                return player;
                // Set class to rogue and give player dagger
            }
            else if (classSelection == "3") {
                starterWeapon = &DAGGER;
                Player player(name, ROGUE);
                player.addItem(starterWeapon);
                return player;
                // Handle invalid input
            }
            else {
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
            }
            else if (selection == "2") {
                cout << "Selling..." << endl;
                break;
            }
            else if (selection == "3") {
                npc.completeQuest(player);
                break;
            }
            else {
                cout << "Invalid selection! Try again!" << endl;
            }
        }
    }

    void playerMvmt(Map& map, Player& player) {
        string selection;
        bool canMoveRight = map.checkValidDir('r');
        bool canMoveLeft = map.checkValidDir('l');
        bool canMoveUp = map.checkValidDir('u');
        bool canMoveDown = map.checkValidDir('d');

        while (true) {

            cout << "Which Direction?" << endl;
            if (canMoveRight) {
                cout << "1 - Move Right" << endl;
            }
            if (canMoveLeft) {
                cout << "2 - Move Left" << endl;
            }
            if (canMoveUp) {
                cout << "3 - Move Up" << endl;
            }
            if (canMoveDown) {
                cout << "4 - Move Down" << endl;
            }

            cin >> selection;
            if (selection == "1" && canMoveRight) {
                cout << "Moving Right..." << endl;
                map.moveCharacter('r', player);
                break;
            }
            else if (selection == "2" && canMoveLeft) {
                cout << "Moving Left..." << endl;
                map.moveCharacter('l', player);
                break;
            }
            else if (selection == "3" && canMoveUp) {
                cout << "Moving Up..." << endl;
                map.moveCharacter('u', player);
                break;
            }
            else if (selection == "4" && canMoveDown) {
                cout << "Moving Down..." << endl;
                map.moveCharacter('d', player);
                break;
            }
            else {
                cout << "Invalid selection! Try again!" << endl;
            }
        }
    }
    //code to call a random enemy type (NOTE: NEED CODE TO CALL CURRENT WEAPON)
    //Enemy* enemies[] = { &GHOSTKNIGHT, &SKELETON, &GOBLIN, &SWARMOFBATS, &DARKMAGE };
    //srand(time(0));
    //int randomIndex = rand() % 5;
    //Enemy* enemy = enemies[randomIndex];
    //combatSystem(player, enemy, DAGGER);
    void combatSystem(Player& player, Enemy* enemy, Weapon& weapon) {
        string move;
        int count = 0;
        //displays name of enemy and starts loop
        cout << "You are fighting: " << enemy->getName() << endl;
        while (player.getCurrHealth() > 0 && enemy->getHealth() > 0)
        {
            //options are displayed with count to allow player to flee
            count = count + 1;
            cout << "1 - Attack" << endl;
            cout << "2 - Ability" << endl;
            cout << "3 - Inventory" << endl;
            cout << "4 - Flee" << endl;
            cin >> move;
            if (move == "1")
            {
                //attacks enemy using damage from current weapon and updates enemy health and displays
                int damage = weapon.getDamage();
                enemy->setHealth(enemy->getHealth() - damage);
                cout << "You attack the enemy with your weapon and did " << damage << " damage!" << endl;
                cout << "Remaining Enemy Health: " << enemy->getHealth() << endl;
            }
            //calls abilites WIP
            else if (move == "2") {
                player.getPlayerClass().specialAbility();
                cout << "You use your special ability!" << endl;
            }
            //can open inventory
            else if (move == "3") {
                cout << "You open your inventory!" << endl;
                player.displayInventory();
            }
            //can flee after 4 moves
            else if (move == "4")
            {
                if (count > 4)
                {
                    cout << "You have fled the fight!" << endl;
                    break;
                }
                else if (count < 4)
                {
                    cout << "Cannot flee until 4 moves have been made" << endl;
                }
            }
            //validate message
            else
            {
				cout << "Invalid selection!" << endl;
            }
            cout << "Enemy Move" << endl;
            int enemyMove = rand() % 2; //Generates random number between 1 and 0 to determin if enemy uses ability or attacks

            if (enemyMove == 0) {
                //function call from enemy class for attack
                if (enemyMove == 0) {
                    enemy->attack();
                    player.setCurrHealth(player.getCurrHealth() - enemy->getDamage());
                    cout << "You Have" << player.getCurrHealth() << " Remaining Health" << endl;
                }
                else if (enemyMove == 1) {
                    //function call from enemy class for ability
                    enemy->specialAbility();

                }

            }
            //if player loses
            if (player.getCurrHealth() <= 0)
            {
                cout << "You lose the fight!" << endl;
                //Display lose screen
                cout << ",---. " << endl;
                cout << ",--.   ,--.,-----. ,--. ,--.    ,--.    ,-----.  ,---. ,------." << endl;
                cout << "|   | " << endl;
                cout << "\\  `.'  /'  .-.  '|  | |  |    |  |   '  .-.  ''   .-'|  .---'" << endl;
                cout << "|  .' " << endl;
                cout << ".    / |  | |  ||  | |  |    |  |   |  | |  |`.  `-.|  `--, " << endl;
                cout << "|  | " << endl;
                cout << "    |  |  '  '-'  ''  '-'  '    |  '--.'  '-'  '.-'    |  `---.`--' " << endl;
                cout << "    `--'   `-----'  `-----'     `-----' `-----' `-----'`------'.--. " << endl;
                cout << "                                                               '--' " << endl;
                //ends fight returns to game and loses
                return;
            }
            else if (enemy->getHealth() <= 0)
                //if player wins returns to game menu
            {
                cout << "You win the fight!" << endl;
                return;

            }
        }
    }
};
