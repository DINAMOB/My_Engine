/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** assets
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

class Assets {
public:
    Assets(const std::string& path);
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
    std::map<std::string, sf::SoundBuffer> sounds;

private:
    bool load_from_json(const std::string& filename);
};