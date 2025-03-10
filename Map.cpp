/*
 * Author(s): Daniel Lebedev
 * Description: Defines Map dunctions.
 */
#include "Map.h"

Map::Map() {
    // Map with everything visible
    fullMap = {
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL},
        {WALL, EMPTY, WALL, EMPTY, WALL, EMPTY, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL, EMPTY, WALL, EMPTY, WALL},
        {WALL, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL, EMPTY, WALL, EMPTY, EMPTY},
        {WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL, EMPTY, WALL, WALL, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL},
        {WALL, WALL, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
    };

    // Map player sees
    playerMap = vector<vector<char>>(MAP_HEIGHT, vector<char>(MAP_WIDTH, FOG));

    // Initialize player position
    playerX = 1;
    playerY = 1;

    // Place player on map
    fullMap[playerY][playerX] = PLAYER;

    // UNFINISHED
    // Add enemies and NPCs to vectors
    enemies.push_back(GOBLIN);
    npcs.push_back(QUEST_GIVER_1);

    // Add enemies to map
    for (Enemy& enemy : enemies) {
        fullMap[enemy.getY()][enemy.getX()] = ENEMY;
    }

    // Add NPCs to map
    for (NPC& npc : npcs) {
        fullMap[npc.getY()][npc.getX()] = MERCHANT;
    }
}

// Displays player's map
void Map::renderMap() {
    updatePlayerMap();
    for(const auto &row : playerMap) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

// Checks if theres an empty space to move to
bool Map::checkValidDir(char dir) const{
    int x = playerX, y = playerY;
    switch (tolower(dir)) {
        case 'r': x += 1; break;  // Right
        case 'l': x -= 1; break;  // Left
        case 'u': y -= 1; break;  // Up
        case 'd': y += 1; break;  // Down
    }
    // False if out of bounds
    if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
        return false;
    }
    // True if not a wall, false if wall
    return fullMap[y][x] != WALL;
}

// Moves the character on the map
void Map::moveCharacter(char dir, Player& player) {
    int newX = playerX, newY = playerY;
    switch (tolower(dir)) {
        case 'r': newX += 2; break;  // Right
        case 'l': newX -= 2; break;  // Left
        case 'u': newY -= 2; break;  // Up
        case 'd': newY += 2; break;  // Down
    }

    checkInteractions(dir, player);

    // If the chosen direction is valid, update full map, then update player map
    if (checkValidDir(dir)) {
        // UNFINISHED
        char currentCell = fullMap[playerY][playerX];
        fullMap[playerY][playerX] = (currentCell == PLAYER) ? EMPTY : currentCell;
        if (fullMap[newY][newX] != ENEMY && fullMap[newY][newX] != MERCHANT) {
            fullMap[newY][newX] = PLAYER; // Only place player if it's not an enemy or NPC
        }

        updatePlayerMap();
        playerX = newX;
        playerY = newY;
        updatePlayerMap();
    }
}

// Copies cells around character from full map to player's map
void Map::updatePlayerMap() {
    playerMap[playerY][playerX] = PLAYER;
    for (int y = max(0, playerY - 2); y <= min(MAP_HEIGHT - 1, playerY + 2); ++y) {
        for (int x = max(0, playerX - 2); x <= min(MAP_WIDTH - 1, playerX + 2); ++x) {
            playerMap[y][x] = fullMap[y][x];
        }
    }
}

// UNFINISHED
void Map::checkInteractions(char dir, Player& player) {
    int newX = playerX, newY = playerY;
    switch (tolower(dir)) {
        case 'r': newX += 2; break;  // Right
        case 'l': newX -= 2; break;  // Left
        case 'u': newY -= 2; break;  // Up
        case 'd': newY += 2; break;  // Down
    }

    if (fullMap[newY][newX] == ENEMY) {
        for (Enemy& enemy : enemies) {
            if (enemy.getX() == newX && enemy.getY() == newY) {
                // UNFINISHED
                cout << "You encountered " << enemy.getName() << endl;
                // Start combat
            }
        }
    } else if (fullMap[newY][newX] == MERCHANT) {
        for (NPC& npc : npcs) {
            if (npc.getX() == newX && npc.getY() == newY) {
                cout << "You encountered " << npc.getName() << "!" << endl;
                npc.NPCDialog(player);
            }
        }
    }
}
