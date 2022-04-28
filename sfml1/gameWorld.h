#include "SFML/Graphics.hpp"

#include "gameTile.h"

#include <vector>

#ifndef SFML1_GAMEWORLD_H
#define SFML1_GAMEWORLD_H


class GameWorld {
    sf::Vector2i exitPosition;
    sf::Vector2i playerPosition;
    std::vector<sf::Vector2i> enemyPositions;
    void setUpInitialState();
    void setUpEnemyPositions();
    void setUpTiles();
public:
    std::vector<std::vector<GameTile *>> tiles;
    int gridLength;
    GameWorld();
};


#endif //SFML1_GAMEWORLD_H
