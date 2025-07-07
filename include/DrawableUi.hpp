/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** drawable_ui
*/

#pragma once
#include <SFML/Graphics.hpp>

class DrawableUi {
public:
    virtual ~DrawableUi() = default;

    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void update(const sf::RenderWindow& window, float& dt) = 0;
};