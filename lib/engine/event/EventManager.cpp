/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** event_manager
*/

#include "EventManager.hpp"

static void close(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::Closed)
        window.close();
}

static void resize(sf::Event& event, sf::RenderWindow& window)
{
    sf::View view;

    if (event.type == sf::Event::Resized) {
        glViewport(0, 0, event.size.width, event.size.height);
        view = window.getView();
        view.setSize(static_cast<float>(event.size.width),
            static_cast<float>(event.size.height));
        view.setCenter(view.getSize() / 2.f);
        window.setView(view);
    }
}

void EventManager::manager(sf::RenderWindow& window)
{
    sf::Event event;

    while (window.pollEvent(event)) {
        close(event, window);
        resize(event, window);
        this->keyboard.handle_event(event);
        this->mouse.handle_event(event);
    }
}