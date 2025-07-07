/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** button_base
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "EventManager.hpp"

class ButtonBase {
public:
    virtual ~ButtonBase() = default;
    virtual bool is_hovered(const sf::RenderWindow& window) const = 0;
    virtual bool is_clicked(const sf::RenderWindow& window) const = 0;
    void set_callback(std::function<void()> cd) { callback = std::move(cd); }

protected:
    std::function<void()> callback = nullptr;
};
