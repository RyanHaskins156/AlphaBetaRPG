/*
 * Author(s): Daniel Lebedev
 * Description: Instantiate valid weapons to be used in game.
 */
#include "Item.h"

// Instantiate weapons/consumables to be used in game.
Weapon CLUB("Club", 15, "blunt");
Weapon STAFF("Staff", 12, "magic");
Weapon DAGGER("Dagger", 10, "pierce");
Weapon WARHAMMER("Warhammer", 20, "blunt");
Weapon SPELL_TOME("Spell Tome", 16, "magic");
Weapon SWORD("Sword", 13, "pierce");
Consumable LESSER_HEALTH("Lesser Health Potion", 20);
Consumable GREATER_HEALTH("Greater Health Potion", 30);
Consumable EPIC_HEALTH("Epic Health Potion", 40);
