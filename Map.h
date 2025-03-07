/*
 * Author(s): Daniel Lebedev
 * Description: Represents the world map with a full map and player view.
 */

#ifndef MAP_H
#define MAP_H
#include <vector>
#include <iostream>
using namespace std;

// Constant vars for map
static const int MAP_WIDTH = 25;
static const int MAP_HEIGHT = 9;
static const char FOG = '-';
static const char WALL = '#';
static const char EMPTY = ' ';
static const char PLAYER = '@';

class Map {
private:
    // Map member variables
    vector<vector<char>> fullMap;
    vector<vector<char>> playerMap;
    int playerX, playerY;

public:
    // Function declarations
    Map();
    void renderMap();
    bool checkValidDir(char dir) const;
    void moveCharacter(char dir);
    void updatePlayerMap();

    // Getters
    int getPlayerX() { return playerX; }
    int getPlayerY() { return playerY; }
};

#endif // MAP_H
