/*
* Classname:   Gaming Platform Frameworks
* Project:     Raven
* Version:     1.0
*
* Copyright:   The contents of this document are the property of its creators.
*              Reproduction or usage of it without permission is prohibited.
*
* Owners:      Will Nations
*              Hailee Ammons
*              Kevin Wang
*/


#include "InputSystem.h"
#include <fstream>

using namespace Raven;


void InputSystem::update(ex::EntityManager &es, ex::EventManager &events,
    ex::TimeDelta dt) {

    es.each<Pawn>([&](ex::Entity entity, Pawn &pawn) {
        entity.component<Rigidbody>()->velocity.x = movementThresX;
        entity.component<Rigidbody>()->velocity.y = movementThresY;
        //events.emit<AudioEvent>(...);
    });
}

/// <summary>
/// Receives KeyboardEvents
/// </summary>
/// <param name="event">The event.</param>
void InputSystem::receive(const KeyboardEvent &event) {
    cout << "Key was pressed : " +
        (event.action == "" ? NO_ACTION_STR : event.action) << endl;
}

int InputSystem::handleEvent(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed: {

            key = getAction(event.key.code);

            if (key == "switch_mode"){
                cout << "Edit Mode = " << editMode << endl;
                if (editMode == true) editMode = false;
                else editMode = true;
            }
            if (!editMode) {
                if (key == "move_right" && movementThresX < 1.0) {
                    movementThresX += (FPS_100_TICK_TIME * 100);
                }

                if (key == "move_down" && movementThresY < 1.0) {
                    movementThresY += (FPS_100_TICK_TIME * 100);
                }

                if (key == "move_left" && movementThresX > -1.0) {
                    movementThresX -= (FPS_100_TICK_TIME * 100);
                }

                if (key == "move_up" && movementThresY > -1.0) {
                    movementThresY -= (FPS_100_TICK_TIME * 100);
                }
                if (key == "play_sound") {
                    //cmn::game->events.emit<AudioEvent>();
                }
            }
            break;
        }
        case sf::Event::KeyReleased: {
            key = getAction(event.key.code);

            if (key == "move_right" || key == "move_left") {
                movementThresX = 0;
            }

            if (key == "move_down" || key == "move_up") {
                movementThresY = 0;
            }

            break;
        }
        case sf::Event::MouseButtonPressed: {
            sf::Vector2i position = sf::Mouse::getPosition();
            //cout << event.mouseButton.x << " " << event.mouseButton.y << endl;
            break;
        }
        case sf::Event::JoystickButtonPressed: {
            movementThresX = 2;
            break;
        }
        case sf::Event::JoystickMoved: {
            movementThresX = 3;
            break;
        }
    }
    return 0;
}

void InputSystem::insert_input(sf::Keyboard::Key key, std::string action) {
    try {
        if (key_map.at(key) != action) {
            key_map[key] = action;
        }
    }
    catch (std::exception e) {
        //If k does not match the key of any element in the container, the function throws an out_of_range exception.
        key_map.insert(std::pair<sf::Keyboard::Key, std::string>(key, action));
    }
}

void InputSystem::read_file(std::string filename) {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        //FILENAME IS BAD
        return;
    }
    std::string action, key;
    while (file >> action) {
        file >> key;
        if ("A" == key) { insert_input(sf::Keyboard::A, action); }
        else if ("B" == key) { insert_input(sf::Keyboard::B, action); }
        else if ("C" == key) { insert_input(sf::Keyboard::C, action); }
        else if ("D" == key) { insert_input(sf::Keyboard::D, action); }
        else if ("E" == key) { insert_input(sf::Keyboard::E, action); }
        else if ("F" == key) { insert_input(sf::Keyboard::F, action); }
        else if ("G" == key) { insert_input(sf::Keyboard::G, action); }
        else if ("H" == key) { insert_input(sf::Keyboard::H, action); }
        else if ("I" == key) { insert_input(sf::Keyboard::I, action); }
        else if ("J" == key) { insert_input(sf::Keyboard::J, action); }
        else if ("K" == key) { insert_input(sf::Keyboard::K, action); }
        else if ("L" == key) { insert_input(sf::Keyboard::L, action); }
        else if ("M" == key) { insert_input(sf::Keyboard::M, action); }
        else if ("N" == key) { insert_input(sf::Keyboard::N, action); }
        else if ("O" == key) { insert_input(sf::Keyboard::O, action); }
        else if ("P" == key) { insert_input(sf::Keyboard::P, action); }
        else if ("Q" == key) { insert_input(sf::Keyboard::Q, action); }
        else if ("R" == key) { insert_input(sf::Keyboard::R, action); }
        else if ("S" == key) { insert_input(sf::Keyboard::S, action); }
        else if ("T" == key) { insert_input(sf::Keyboard::T, action); }
        else if ("U" == key) { insert_input(sf::Keyboard::U, action); }
        else if ("V" == key) { insert_input(sf::Keyboard::V, action); }
        else if ("W" == key) { insert_input(sf::Keyboard::W, action); }
        else if ("X" == key) { insert_input(sf::Keyboard::X, action); }
        else if ("Y" == key) { insert_input(sf::Keyboard::Y, action); }
        else if ("Z" == key) { insert_input(sf::Keyboard::Z, action); }
        else if ("Num0" == key) { insert_input(sf::Keyboard::Num0, action); }
        else if ("Num1" == key) { insert_input(sf::Keyboard::Num1, action); }
        else if ("Num2" == key) { insert_input(sf::Keyboard::Num2, action); }
        else if ("Num3" == key) { insert_input(sf::Keyboard::Num3, action); }
        else if ("Num4" == key) { insert_input(sf::Keyboard::Num4, action); }
        else if ("Num5" == key) { insert_input(sf::Keyboard::Num5, action); }
        else if ("Num6" == key) { insert_input(sf::Keyboard::Num6, action); }
        else if ("Num7" == key) { insert_input(sf::Keyboard::Num7, action); }
        else if ("Num8" == key) { insert_input(sf::Keyboard::Num8, action); }
        else if ("Num9" == key) { insert_input(sf::Keyboard::Num9, action); }
        else if ("Escape" == key) { insert_input(sf::Keyboard::Escape, action); }
        else if ("LControl" == key) { insert_input(sf::Keyboard::LControl, action); }
        else if ("LShift" == key) { insert_input(sf::Keyboard::LShift, action); }
        else if ("LAlt" == key) { insert_input(sf::Keyboard::LAlt, action); }
        else if ("Tilde" == key) { insert_input(sf::Keyboard::Tilde, action); }
        else if ("Left" == key) { insert_input(sf::Keyboard::Left, action); }
        else if ("Right" == key) { insert_input(sf::Keyboard::Right, action); }
        else if ("Up" == key) { insert_input(sf::Keyboard::Up, action); }
        else if ("Down" == key) { insert_input(sf::Keyboard::Down, action); }
    }

}