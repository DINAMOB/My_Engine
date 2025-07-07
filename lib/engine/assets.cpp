/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** assets
*/

#include "assets.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

Assets::Assets(const std::string& path)
{
    load_from_json(path);
}

bool Assets::load_from_json(const std::string& filename) {
    sf::SoundBuffer buffer;
    sf::Texture tex;
    sf::Font font;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open JSON file: " << filename << "\n";
        return false;
    }
    json j;
    file >> j;
    if (j.contains("textures")) {
        for (auto& [name, path] : j["textures"].items()) {
            if (!tex.loadFromFile(path)) {
                std::cerr << "Failed to load texture '" << name << "' from " << path << "\n";
                return false;
            }
            textures[name] = std::move(tex);
            std::cout << "Texture: " << name << " load.\n";
        }
    }
    if (j.contains("fonts")) {
        for (auto& [name, path] : j["fonts"].items()) {
            if (!font.loadFromFile(path)) {
                std::cerr << "Failed to load font '" << name << "' from " << path << "\n";
                return false;
            }
            fonts[name] = std::move(font);
            std::cout << "Font: " << name << " load.\n";
        }
    }
    if (j.contains("sounds")) {
        for (auto& [name, path] : j["sounds"].items()) {
            sf::SoundBuffer buffer;
            if (!buffer.loadFromFile(path)) {
                std::cerr << "Failed to load sound '" << name << "' from " << path << "\n";
                return false;
            }
            sounds[name] = std::move(buffer);
            std::cout << "Sound: " << name << " load.\n";
        }
    }
    return true;
}