/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** rect_button
*/

#pragma once
#include "button_base.hpp"
#include "DrawableUi.hpp"

class RectButton : public ButtonBase, public DrawableUi {
public:
    RectButton(const sf::Font& font, sf::Vector2f pos, sf::Vector2f size, const std::string& label);
    void draw(sf::RenderWindow& window) const override;
    void update(const sf::RenderWindow& window, float& dt) override;
    bool is_hovered(const sf::RenderWindow& window) const override;
    bool is_clicked(const sf::RenderWindow& window) const override;
    void set_color(sf::Color idle, sf::Color hover);

private:
    sf::RectangleShape rect;
    sf::Text text;
    sf::Font font;
    sf::Color idle_color;
    sf::Color hover_color;
    sf::Color pressed_color;
};