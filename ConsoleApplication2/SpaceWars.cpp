// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "Background.h"
#include "InfoBox.h"
#include "SpaceObjectsManager.h"
#include "EnemiesCreator.h"
#include "Player.h"

int main()
{
    unsigned int windowX = 1500;
    unsigned int windowY = 800;

    //InfoBox infobox(&spaceship);
    
    sf::RenderWindow window(sf::VideoMode({ windowX, windowY }), "Space Wars!");
    window.setFramerateLimit(60);

    Player Player(&window);
    Background Background(&window);
    SpaceObjectsManager SpaceObjectsManager(&window);
    SpaceObjectsManager.addObject(Player.spaceship);
    EnemiesCreator EnemiesCreator(&window, &SpaceObjectsManager);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                Player.onKeyPressed(keyPressed->scancode);
            } else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                Player.onKeyReleased(keyReleased->scancode);
            }
        }
  
        window.clear();
 
        Background.move();
        Background.draw();
        EnemiesCreator.create();
        SpaceObjectsManager.move();

        //window.draw(infobox);
        window.display();
    }
}