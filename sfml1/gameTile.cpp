#include <iostream>
#include "gameTile.h"

GameTile::GameTile(std::string textureName, float x, float y, bool isFree, bool isExit) {
    if(!setUpSprite(textureName)){
        return;
    }

    position = sf::Vector2f(x, y);
    sprite.setPosition(position);
    this->isFree = isFree;
    this->isExit = isExit;
}

bool GameTile::setUpSprite(std::string textureName) {
    if(!texture.loadFromFile( path + "images/sprites/tilesets/" + textureName)){
        std::cout<<"bad!";
        return false;
    }
    std::cout<<"good!" << std::endl;
    std::cout<< path + "images/sprites/tilesets/" + textureName << std::endl;

    this->texture.setSmooth(true);
    sf::Sprite sprite;
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));

    return true;
}