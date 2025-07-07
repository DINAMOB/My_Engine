/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** scene_manager
*/

#include "SceneManager.hpp"

Scene& SceneManager::create_scene(const std::string& key)
{
    std::unique_ptr<Scene> scene = std::make_unique<Scene>();
    Scene* ptr = scene.get();

    scenes[key] = std::move(scene);
    return *ptr;
}

void SceneManager::set_active(const std::string& key)
{
    std::unordered_map<std::string, std::unique_ptr<Scene>>::iterator it = scenes.find(key);
    if (it != scenes.end())
        current = it->second.get();
}

Scene* SceneManager::get_active() const
{
    return current;
}

Scene* SceneManager::get_scene(const std::string& key) const
{
    std::unordered_map<std::string, std::unique_ptr<Scene>>::const_iterator it = scenes.find(key);
    if (it != scenes.end())
        return  it->second.get();
    return nullptr;
}