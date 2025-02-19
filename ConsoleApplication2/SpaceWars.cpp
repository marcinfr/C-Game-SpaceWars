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
#include "Menu.h"
#include "Stage.h"

int main()
{
    unsigned int windowX = 1500;
    unsigned int windowY = 800;
    
    sf::RenderWindow window(sf::VideoMode({ windowX, windowY }), "Space Wars!");
    window.setFramerateLimit(60);

    Stage Stage(&window);
    Player Player(&window);
    Background Background(&window);
    SpaceObjectsManager SpaceObjectsManager(&window);
    SpaceObjectsManager.addObject(Player.spaceship);
    EnemiesCreator EnemiesCreator(&window, &SpaceObjectsManager);
    InfoBox infobox(&Player, &window);
    Menu Menu(&window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                switch (keyPressed->scancode) {
                    case sf::Keyboard::Scancode::Escape:
                    Menu.display = !Menu.display;
                    break;
                default:
                    Player.onKeyPressed(keyPressed->scancode);
                }
            } else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                Player.onKeyReleased(keyReleased->scancode);
            }
        }

        if (Player.spaceship->life <= 0) {
        //    Menu.display = 1;
        }
  
        window.clear();
 
        if (!Menu.display) {
            Background.move();
            EnemiesCreator.stage = Stage.stage;
            EnemiesCreator.create();
            SpaceObjectsManager.move();
        }
        
        Background.draw();
        SpaceObjectsManager.draw();
        window.draw(infobox);

        if (!Menu.display) {
            Stage.process();
        }

        if (Menu.display) {
            window.draw(Menu);
        }

        window.display();
    }
}