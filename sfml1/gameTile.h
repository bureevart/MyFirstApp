#include <SFML/Graphics.hpp>

#ifndef SFML1_GAMETILE_H
#define SFML1_GAMETILE_H

using namespace sf;
class GameTile {
public:
    std::string path = "Z:/javaProjects/ClionProjects/sfml1/";
    bool isFree;
    bool isExit;

    Vector2f position;
    Texture texture;
    Sprite sprite;

    GameTile(std::string, float, float, bool, bool);

    bool setUpSprite(std::string);

};


#endif //SFML1_GAMETILE_H
