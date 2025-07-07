/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** scene_manager
*/

#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "Scene.hpp"

class SceneManager {
public:
    Scene& create_scene(const std::string& key);
    void set_active(const std::string& key);
    Scene* get_active() const;
    Scene* get_scene(const std::string& key) const;

private:
    std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
    Scene* current = nullptr;
};