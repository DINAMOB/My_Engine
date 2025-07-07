/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** grid
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DrawableUi.hpp"

class grid_c : public DrawableUi {
public:
    grid_c(int cols, int rows, float cell_size, sf::Color color = sf::Color::White, float thickness = 1.0f);

    void set_position(sf::Vector2f pos);
    void update(const sf::RenderWindow& window, float& dt) override;
    void draw(sf::RenderWindow& window) const override;

private:
    std::vector<sf::RectangleShape> lines;
    int cols;
    int rows;
    float cell_size;
    sf::Color line_color;
    float line_thickness;
    sf::Vector2f position;
};
