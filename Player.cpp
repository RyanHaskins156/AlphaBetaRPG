/*
 * Author(s): Daniel Lebedev
 * Description: Defines Player class functions.
 */
#include "Player.h"

// Print basic player info for debugging
void Player::printPlayer() {
    cout << name << " " << playerClass.className << " " << currHealth << endl;
}

// Add item to player's inventory
void Player::addItem(Item* item) {
    // Loop through inventory, if item exists, increase quantity
    for (auto& pair : inventory) {
        if (pair.first == item) {
            pair.second += 1;
            return;
        }
    }

    // If item not in inventory already, add new Item to inventory
    inventory.push_back(make_pair(item, 1));
}

// Remove item from player's inventory
void Player::removeItem(Item* item) {
    // Loop through inventory and create iterator to handle removal
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->first == item) {
            // If more than one item, update quantity
            if (it->second > 1) {
                it->second -= 1;
            // If only one item, remove from inventory completely
            } else {
                inventory.erase(it);
            }
            return;
        }
    }
}

// Use item in player's inventory
void Player::useItem(int index) {
    // If valid selection, use item
    if (index >= 0 && index < inventory.size()) {
        Item* item = inventory[index].first;
        item->use();
        if (dynamic_cast<Weapon*>(item) == nullptr) {
            removeItem(item);
        }
    } else {
        cout << "Invalid index. No items used." << endl;
    }
}

void Player::displayInventory() {
    cout << "\nInventory:" << endl;
    for (size_t i = 0; i < inventory.size(); i++) {
        cout << i << ": " << inventory[i].first->getName() << " (x" << inventory[i].second << ")" << endl;
    }

    string selection;
    cout << "\nWhat would you like to do?" << endl;
    cout << "1 - Use an Item" << endl;
    cout << "2 - Close Inventory" << endl;
    cin >> selection;

    if (selection == "1") {
        size_t index;
        cout << "Enter the index of the item:" << endl;
        cin >> index;
        useItem(index);
    } else {
        cout << "Closing Inventory..." << endl;
    }
}

