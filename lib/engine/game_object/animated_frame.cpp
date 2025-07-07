/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** animated_frame
*/

#include "animated_frame.hpp"
#include <iostream>
#include <iomanip>

AnimatedFrame::AnimatedFrame(const sf::Texture& texture, sf::Vector2i size, int count, float time)
    : tex(texture), f_size(size), f_count(count), f_time(time)
{
    this->sp.setTexture(this->tex);
    this->sp.setTextureRect(sf::IntRect(0, 0, this->f_size.x, this->f_size.y));
}

void AnimatedFrame::set_position(sf::Vector2f pos)
{
    this->sp.setPosition(pos);
}

void AnimatedFrame::set_scale(sf::Vector2f scale)
{
    this->sp.setScale(scale);
}

void AnimatedFrame::draw(sf::RenderWindow& window) const
{
    window.pushGLStates();
    window.draw(this->sp);
    window.popGLStates();
}

void AnimatedFrame::update(const sf::RenderWindow&, float& dt)
{
    sf::IntRect rect;

    this->time_since_last_f += dt;
    if (this->time_since_last_f >= this->f_time) {
        this->time_since_last_f = 0.0f;
        this->current_f = (this->current_f + 1) % this->f_count;
        rect = sf::Rect(0, this->current_f * this->f_size.y,
            this->f_size.x,
            this->f_size.y
        );
        this->sp.setTextureRect(rect);
    }
}