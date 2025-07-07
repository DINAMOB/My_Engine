/*
** EPITECH PROJECT, 2025
** Engine_sfml
** File description:
** RenderEngine
*/

#pragma once
#include "EventManager.hpp"
#include "RenderOpenGL.hpp"
#include "SceneManager.hpp"
#include <GL/glu.h>

#define CONTEXT_2D_SETTING sf::ContextSettings{0, 0, 0, 2, 0}
#define CONTEXT_3D_SETTING sf::ContextSettings{24, 8, 4, 3, 0}

class RenderEngine {
public:
    RenderEngine(sf::VideoMode mode,
        const std::string& title,
        uint32_t style = sf::Style::Default,
        const sf::ContextSettings& settings = sf::ContextSettings()
    );
    void run(SceneManager& manager);
private:
    void clear(const sf::Color color);
    void dtUpdate(void);
    float dt;
    sf::Clock delta_time;
    EventManager event;
    RenderOpenGL openGL;
    sf::RenderWindow window;
};
