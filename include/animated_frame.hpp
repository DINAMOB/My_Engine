/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** animated_frame
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "DrawableUi.hpp"

class AnimatedFrame : public DrawableUi {
public:
    AnimatedFrame(const sf::Texture& texture, sf::Vector2i size, int f_count, float f_time);
    void set_position(sf::Vector2f pos);
    void set_scale(sf::Vector2f sclale);
    void update(const sf::RenderWindow& window, float& dt) override;
    void draw(sf::RenderWindow& window) const override;

private:
    const sf::Texture& tex;
    sf::Sprite sp;
    sf::Vector2i f_size;
    int f_count;
    float f_time;
    int current_f = 0;
    float time_since_last_f = 0.0f;
};