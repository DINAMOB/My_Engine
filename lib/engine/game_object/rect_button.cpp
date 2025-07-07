/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** rect_button
*/

#include "rect_button.hpp"

#include "rect_button.hpp"
#include <SFML/Window/Mouse.hpp>

RectButton::RectButton(const sf::Font& font, sf::Vector2f pos, sf::Vector2f size, const std::string& label)
{
    this->rect.setPosition(pos);
    this->rect.setSize(size);
    this->rect.setFillColor(idle_color);

    this->text.setFont(font);
    this->text.setString(label);
    this->text.setCharacterSize(static_cast<unsigned int>(size.y * 0.5f));
    this->text.setFillColor(sf::Color::White);
    sf::FloatRect textBounds = this->text.getLocalBounds();
    this->text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
    this->text.setPosition(pos + size / 2.f);

    this->idle_color = sf::Color(100, 100, 100);
    this->hover_color = sf::Color(150, 150, 150);
    this->pressed_color = sf::Color(200, 200, 200);
}



void RectButton::set_color(sf::Color idle, sf::Color hover)
{
    this->idle_color = idle;
    this->hover_color = hover;
}

bool RectButton::is_hovered(const sf::RenderWindow& window) const
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    return this->rect.getGlobalBounds().contains(mousePos);
}

bool RectButton::is_clicked(const sf::RenderWindow& window) const
{
    return is_hovered(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void RectButton::update(const sf::RenderWindow& window, float& dt)
{
    if (is_clicked(window)) {
        this->rect.setFillColor(this->pressed_color);
        if (this->callback) {
            static float wait_time = 0.1f;
            static float acc_time = 0.0f;
            acc_time += dt;
            if (acc_time >= wait_time) {
                this->callback();
                acc_time = 0.0f;
            }
        }
    } else if (is_hovered(window)) {
        this->rect.setFillColor(this->hover_color);
    } else {
        this->rect.setFillColor(this->idle_color);
    }
}

void RectButton::draw(sf::RenderWindow& window) const
{
    window.pushGLStates();
    window.draw(this->rect);
    window.draw(this->text);
    window.popGLStates();
}
