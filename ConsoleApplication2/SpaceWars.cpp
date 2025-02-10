// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "Spaceship.h"
#include "Background.h"
#include "Enemies.h"
#include "InfoBox.h"

int main()
{
    unsigned int windowX = 1200;
    unsigned int windowY = 800;

    Spaceship spaceship;
    Background background(windowX, windowY, 100);
    Enemies enemies(windowX, windowY);
    InfoBox infobox(&spaceship);
    
    sf::RenderWindow window(sf::VideoMode({ windowX, windowY }), "SFML works!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                switch (keyPressed->scancode) {
                    case sf::Keyboard::Scancode::Up:
                        spaceship.moveUp();
                        break;
                    case sf::Keyboard::Scancode::Down:
                        spaceship.moveDown();
                        break;
                    case sf::Keyboard::Scancode::Right:
                        spaceship.moveForward();
                        break;
                    case sf::Keyboard::Scancode::Left:
                        spaceship.moveBackward();
                        break;
                }
            }
            
            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                switch (keyReleased->scancode) {
                    case sf::Keyboard::Scancode::Right:
                    case sf::Keyboard::Scancode::Left:
                        spaceship.resetSpeedX();
                    case sf::Keyboard::Scancode::Up:
                    case sf::Keyboard::Scancode::Down:
                        spaceship.resetSpeedY();
                }
            }
        }

        window.clear();

        enemies.setPlayerSpaceship(&spaceship);

        spaceship.move();
        enemies.move();
        background.move();

        window.draw(background);
        window.draw(enemies);
        window.draw(spaceship);

        window.draw(infobox);

        window.display();
    }
}