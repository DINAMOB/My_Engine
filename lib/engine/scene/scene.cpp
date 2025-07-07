/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** scene
*/

#include "Scene.hpp"

void Scene::add(std::unique_ptr<DrawableUi> obj)
{
    objects.push_back(std::move(obj));
}

void Scene::draw(sf::RenderWindow& window) const
{
    for (const std::unique_ptr<DrawableUi>& obj : objects)
        obj->draw(window);
}

void Scene::update(const sf::RenderWindow& window, float& dt)
{
    for (const std::unique_ptr<DrawableUi>& obj : objects)
        obj->update(window, dt);
}
