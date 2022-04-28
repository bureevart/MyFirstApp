#include <iostream>

#include <SFML/Graphics.hpp>

#include "gameTile.h"

#include "gameWorld.h"

#include "cmath"

using namespace sf;

///Управление персонажем с анимацией///
//todo сделать отдельные обработчики для диагонального перемещения и  автозавершение прыжка (хз)
void slimeMoving(Sprite* slime, float* CurrentFrame, float* animationSpeed, int* slimeFrames, int* slimeSize, float* slimeSpeed , float* time, bool* isMoveToLeftSideBefore) {
    if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))) && (Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
        *CurrentFrame += *animationSpeed * *time;
        if (*CurrentFrame > *slimeFrames) *CurrentFrame -= *slimeFrames;
        (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame), 0, *slimeSize, *slimeSize));

        (*slime).move(*slimeSpeed / sqrt(2), *slimeSpeed / sqrt(2) * *time);
        *isMoveToLeftSideBefore = false;

    } else if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))) && (Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
        *CurrentFrame += *animationSpeed * *time;
        if (*CurrentFrame > *slimeFrames) *CurrentFrame -= *slimeFrames;
        (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame), 0, *slimeSize, *slimeSize));

        (*slime).move(*slimeSpeed / sqrt(2), -*slimeSpeed / sqrt(2) * *time);
        *isMoveToLeftSideBefore = false;

    } else if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))) && (Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
        *CurrentFrame += *animationSpeed * *time;
        if (*CurrentFrame > *slimeFrames) *CurrentFrame -= *slimeFrames;
        (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame) + *slimeSize, 0, -*slimeSize, *slimeSize));

        (*slime).move(-*slimeSpeed / sqrt(2), -*slimeSpeed / sqrt(2) * *time);
        *isMoveToLeftSideBefore = true;

    } else if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))) && (Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
        *CurrentFrame += *animationSpeed * *time;
        if (*CurrentFrame > *slimeFrames) *CurrentFrame -= *slimeFrames;
        (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame) + *slimeSize, 0, -*slimeSize, *slimeSize));

        (*slime).move(-*slimeSpeed / sqrt(2), *slimeSpeed / sqrt(2) * *time);
        *isMoveToLeftSideBefore = true;
    }


    else if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
        //slime.setScale(1, 1);
        *CurrentFrame += *animationSpeed * *time;
        if (*CurrentFrame > *slimeFrames) *CurrentFrame -= *slimeFrames;
        (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame), 0, *slimeSize, *slimeSize));

        (*slime).move(*slimeSpeed * *time, 0);
        *isMoveToLeftSideBefore = false;

    } else if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
        *CurrentFrame += *animationSpeed * *time;
        if (*CurrentFrame > *slimeFrames) *CurrentFrame -= *slimeFrames;
        if(*isMoveToLeftSideBefore)
            (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame) + *slimeSize, 0, -*slimeSize, *slimeSize));
        else
            (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame), 0, *slimeSize, *slimeSize));
        (*slime).move(0, -*slimeSpeed * *time);

    } else if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
        *CurrentFrame += *animationSpeed * *time;
        if (*CurrentFrame > *slimeFrames) *CurrentFrame -= *slimeFrames;
        if(*isMoveToLeftSideBefore)
            (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame) + *slimeSize, 0, -*slimeSize, *slimeSize));
        else
            (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame), 0, *slimeSize, *slimeSize));
        (*slime).move(0, *slimeSpeed * *time);

    } else if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
        //slime.setScale(-1, 1);
        *CurrentFrame += *animationSpeed * *time;
        if (*CurrentFrame > *slimeFrames) *CurrentFrame -= *slimeFrames;
        (*slime).setTextureRect(IntRect(*slimeSize * int(*CurrentFrame) + *slimeSize, 0, -*slimeSize, *slimeSize));
        (*slime).move(-*slimeSpeed * *time, 0);
        *isMoveToLeftSideBefore = true;

    }
}

int main()
{
    std::string path = "Z:/javaProjects/ClionProjects/sfml1/";

    GameWorld gameWorld = GameWorld();

    float windowHeight = 128;
    float windowWidth = 128;

    float currentFrame = 0; //хранит текущий кадр
    Clock clock;

    sf::RectangleShape rectangleShape(sf::Vector2f(windowWidth, windowHeight));
    rectangleShape.setFillColor(sf::Color(80,155,102));

    //создание окна
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "App!");

    Texture texture;
    if(!texture.loadFromFile( path + "images/sprites/characters/slimeMoving.png")){
        return 0;
    }

    Sprite slime;
    int slimeSize = 32;
    int slimeFrames = 6;
    float slimeSpeed = 0.02;
    float animationSpeed = 0.005;
    bool isMoveToLeftSideBefore = false;

    slime.setTexture(texture);
    slime.setTextureRect(IntRect(32, 0, slimeSize, slimeSize));

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event))
        {
            //закрытие окна
            if (event.type == Event::Closed) window.close();
        }

        // перемещение
        slimeMoving(
                &slime,
                &currentFrame,
                &animationSpeed,
                &slimeFrames,
                &slimeSize,
                &slimeSpeed,
                &time, &isMoveToLeftSideBefore);


        window.clear();
        window.draw(rectangleShape);
        for (int i = 0; i < gameWorld.gridLength; i++) {
            for (int j = 0; j < gameWorld.gridLength; j++) {
                window.draw(gameWorld.tiles[i][j]->sprite);
            }
        }

        window.draw(slime);
        window.display();
    }

    return 0;
}
