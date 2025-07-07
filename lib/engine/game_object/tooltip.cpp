/*
** EPITECH PROJECT, 2025
** tooltip
** File description:
** tooltip
*/
#include "tooltip.hpp"

Tooltip::Tooltip(const Assets& asset, const sf::Vector2f& size, const sf::Color& text_color = sf::Color::White)
{
    this->base_text_color = text_color;
    this->font = asset.fonts.at("winXP");
    this->text.setFont(this->font);
    this->text.setCharacterSize(14);
    this->text.setFillColor(this->base_text_color);
    this->background.setFillColor(sf::Color(0, 0, 0, 180));
    this->background.setOutlineColor(sf::Color::White);
    this->background.setOutlineThickness(1.f);
    this->background.setSize(size);
}

Tooltip::~Tooltip() {}

void Tooltip::setText(const std::string& content)
{
    sf::FloatRect bounds = {};

    this->text.setString(content);
    bounds = this->text.getLocalBounds();
    this->background.setSize({bounds.width + 2 * this->padding, bounds.height + 2 * this->padding});
}

void Tooltip::setPosition(const sf::Vector2f& pos)
{
    this->background.setPosition(pos);
    this->text.setPosition(pos.x + this->padding, pos.y + this->padding);
}

void Tooltip::setVisibility(const sf::Vector2f& mouse_pos)
{
    if (this->background.getGlobalBounds().contains(mouse_pos) == true) {
        show();
    } else
        hide();
}

void Tooltip::draw(sf::RenderWindow& window) const
{
    if (!this->visible)
        return;
    window.draw(this->background);
    window.draw(this->text);
}

void Tooltip::show()
{
    if (!this->visible) {
        this->appearing = true;
        this->animationProgress = 0.f;
        this->animationClock.restart();
        this->visible = true;
    }
}

void Tooltip::hide()
{
    if (this->visible) {
        this->appearing = false;
        this->animationProgress = 1.f;
        this->animationClock.restart();
        this->visible = false;
        this->background.setFillColor(sf::Color(0, 0, 0, 0));
        this->text.setFillColor(sf::Color(255, 255, 255, 0));
    }
}

void Tooltip::update(const sf::RenderWindow& window)
{
    this->setVisibility(sf::Vector2f(sf::Mouse::getPosition(window)));
    this->update_tooltip();
}

void Tooltip::update_tooltip()
{
    float elapsed_time = 0.0f;
    int text_alpha = 0;
    int alpha = 0;
    sf::Color tmp;

    if (!this->appearing)
        return;
    elapsed_time = this->animationClock.getElapsedTime().asSeconds();
    this->animationProgress = std::min(elapsed_time / this->animationDuration, 1.f);
    alpha = static_cast<int>(180 * this->animationProgress);
    this->background.setFillColor(sf::Color(0, 0, 0, alpha));
    text_alpha = static_cast<int>(this->base_text_color.a * this->animationProgress);
    text_alpha = std::clamp(text_alpha, 0, 255);
    tmp = this->base_text_color;
    tmp.a = static_cast<sf::Uint8>(text_alpha);
    this->text.setFillColor(tmp);
    if (this->animationProgress >= 1.f)
        this->appearing = false;
}

