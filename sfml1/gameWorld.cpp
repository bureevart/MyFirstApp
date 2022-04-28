#include "gameWorld.h"

GameWorld::GameWorld() {
    gridLength = 8;

    setUpInitialState();
    setUpTiles();
    setUpEnemyPositions();
}

void GameWorld::setUpInitialState() {
//    exitPosition = sf::Vector2i(1, 0);
//    playerPosition = sf::Vector2i (gridLength - 1, gridLength - 1);
}

void GameWorld::setUpEnemyPositions() {
    enemyPositions.clear();
//    enemyPositions.push_back(sf::Vector2i(2,0));
//    enemyPositions.push_back(sf::Vector2i(6,0));
//    enemyPositions.push_back(sf::Vector2i(2,7));
}

void GameWorld::setUpTiles() {
    tiles.clear();

    std::vector<GameTile *> row1;
    row1.push_back(new GameTile("horisontal_fence.png", 0, 0, false, false));
    row1.push_back(new GameTile("horisontal_fence.png", 16, 0, false, false));
    row1.push_back(new GameTile("horisontal_fence.png", 32, 0, false, false));
    row1.push_back(new GameTile("horisontal_fence.png", 48, 0, false, false));
    row1.push_back(new GameTile("horisontal_fence.png", 64, 0, false, false));
    row1.push_back(new GameTile("horisontal_fence.png", 80, 0, false, false));
    row1.push_back(new GameTile("horisontal_fence.png", 96, 0, false, false));
    row1.push_back(new GameTile("horisontal_fence.png", 112, 0, false, false));
    tiles.push_back(row1);

    std::vector<GameTile *> row2;
    row2.push_back(new GameTile("vertical_fence.png", 0, 16, false, false));
    row2.push_back(new GameTile("grass.png", 16, 16, true, false));
    row2.push_back(new GameTile("grass.png", 32, 16, true, false));
    row2.push_back(new GameTile("grass.png", 48, 16, true, false));
    row2.push_back(new GameTile("grass.png", 64, 16, true, false));
    row2.push_back(new GameTile("grass.png", 80, 16, true, false));
    row2.push_back(new GameTile("grass.png", 96, 16, true, false));
    row2.push_back(new GameTile("vertical_fence.png", 112, 16, false, false));
    tiles.push_back(row2);

    std::vector<GameTile *> row3;
    row3.push_back(new GameTile("vertical_fence.png", 0, 32, false, false));
    row3.push_back(new GameTile("grass.png", 16, 32, true, false));
    row3.push_back(new GameTile("grass.png", 32, 32, true, false));
    row3.push_back(new GameTile("grass.png", 48, 32, true, false));
    row3.push_back(new GameTile("grass.png", 64, 32, true, false));
    row3.push_back(new GameTile("grass.png", 80, 32, true, false));
    row3.push_back(new GameTile("grass.png", 96, 32, true, false));
    row3.push_back(new GameTile("vertical_fence.png", 112, 32, false, false));
    tiles.push_back(row3);

    std::vector<GameTile *> row4;
    row4.push_back(new GameTile("vertical_fence.png", 0, 48, false, false));
    row4.push_back(new GameTile("grass.png", 16, 48, true, false));
    row4.push_back(new GameTile("grass.png", 32, 48, true, false));
    row4.push_back(new GameTile("grass.png", 48, 48, true, false));
    row4.push_back(new GameTile("grass.png", 64, 48, true, false));
    row4.push_back(new GameTile("grass.png", 80, 48, true, false));
    row4.push_back(new GameTile("grass.png", 96, 48, true, false));
    row4.push_back(new GameTile("vertical_fence.png", 112, 48, false, false));
    tiles.push_back(row4);

    std::vector<GameTile *> row5;
    row5.push_back(new GameTile("vertical_fence.png", 0, 64, false, false));
    row5.push_back(new GameTile("grass.png", 16, 64, true, false));
    row5.push_back(new GameTile("grass.png", 32, 64, true, false));
    row5.push_back(new GameTile("grass.png", 48, 64, true, false));
    row5.push_back(new GameTile("grass.png", 64, 64, true, false));
    row5.push_back(new GameTile("grass.png", 80, 64, true, false));
    row5.push_back(new GameTile("grass.png", 96, 64, true, false));
    row5.push_back(new GameTile("vertical_fence.png", 112, 64, false, false));
    tiles.push_back(row5);

    std::vector<GameTile *> row6;
    row6.push_back(new GameTile("vertical_fence.png", 0, 80, false, false));
    row6.push_back(new GameTile("grass.png", 16, 80, true, false));
    row6.push_back(new GameTile("grass.png", 32, 80, true, false));
    row6.push_back(new GameTile("grass.png", 48, 80, true, false));
    row6.push_back(new GameTile("grass.png", 64, 80, true, false));
    row6.push_back(new GameTile("grass.png", 80, 80, true, false));
    row6.push_back(new GameTile("grass.png", 96, 80, true, false));
    row6.push_back(new GameTile("vertical_fence.png", 112, 80, false, false));
    tiles.push_back(row6);

    std::vector<GameTile *> row7;
    row7.push_back(new GameTile("vertical_fence.png", 0, 96, false, false));
    row7.push_back(new GameTile("grass.png", 16, 96, true, false));
    row7.push_back(new GameTile("grass.png", 32, 96, true, false));
    row7.push_back(new GameTile("grass.png", 48, 96, true, false));
    row7.push_back(new GameTile("grass.png", 64, 96, true, false));
    row7.push_back(new GameTile("grass.png", 80, 96, true, false));
    row7.push_back(new GameTile("grass.png", 96, 96, true, false));
    row7.push_back(new GameTile("vertical_fence.png", 112, 96, false, false));
    tiles.push_back(row7);

    std::vector<GameTile *> row8;
    row8.push_back(new GameTile("horisontal_fence.png", 0, 112, false, false));
    row8.push_back(new GameTile("horisontal_fence.png", 16, 112, false, false));
    row8.push_back(new GameTile("horisontal_fence.png", 32, 112, false, false));
    row8.push_back(new GameTile("horisontal_fence.png", 48, 112, false, false));
    row8.push_back(new GameTile("horisontal_fence.png", 64, 112, false, false));
    row8.push_back(new GameTile("horisontal_fence.png", 80, 112, false, false));
    row8.push_back(new GameTile("horisontal_fence.png", 96, 112, false, false));
    row8.push_back(new GameTile("horisontal_fence.png", 112, 112, false, false));
    tiles.push_back(row8);

}