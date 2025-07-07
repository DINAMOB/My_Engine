/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** scene
*/


#pragma once
#include <vector>
#include <memory>
#include "DrawableUi.hpp"

class Scene {
public:
    void add(std::unique_ptr<DrawableUi> obj);
    void draw(sf::RenderWindow& window) const;
    void update(const sf::RenderWindow& window, float& dt);

private:
    std::vector<std::unique_ptr<DrawableUi>> objects;
};