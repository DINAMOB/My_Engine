/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** event_manager
*/

#pragma once
#include "input_keyboard.hpp"
#include "input_mouse.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class EventManager {
public:
    InputKeyboard keyboard;
    InputMouse mouse;
    void manager(sf::RenderWindow& window);
};