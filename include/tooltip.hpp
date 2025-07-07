/*
** EPITECH PROJECT, 2025
** tooltip_hpp
** File description:
** tooltip_hpp
*/
#pragma once
#include "engine_sfml.hpp"
#include "assets.hpp"
#include "DrawableUi.hpp"
#include <memory.h>

class Tooltip : public DrawableUi {
    public:
        Tooltip(const Assets& asset, const sf::Vector2f& size, const sf::Color& text_color);
        ~Tooltip();
        void setText(const std::string& content);
        void setPosition(const sf::Vector2f& pos);
        void draw(sf::RenderWindow& window) const override;
        void update(const sf::RenderWindow& window);
    private:
        sf::RectangleShape background;
        sf::Text text;
        sf::Font font;
        float padding = 8.f;
        bool visible = false;
        bool appearing = false;
        float animationProgress = 0.f;
        float animationDuration = 0.25f;
        sf::Clock animationClock;
        sf::Color base_text_color;
        void setVisibility(const sf::Vector2f& mouse_pos);
        void show();
        void hide();
        void update_tooltip();
};
