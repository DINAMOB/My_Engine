/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** input_mouse
*/

#pragma once

#include <SFML/Window.hpp>
#include <unordered_map>

typedef enum mouse_button {
    MOUSE_LEFT,
    MOUSE_RIGHT,
    MOUSE_MIDDLE,
    MOUSE_XBUTTON1,
    MOUSE_XBUTTON2,
} mouse_btn_t;

class InputMouse {
public:
    InputMouse();
    void handle_event(const sf::Event& event);
    bool is_active(mouse_btn_t act) const;
    int get_scroll() const;
private:
    std::unordered_map<sf::Mouse::Button, mouse_btn_t> mouse_to_action;
    std::unordered_map<mouse_btn_t, bool> mouse_state;
    int scroll;
    void map_mouse_btn(sf::Mouse::Button btn, mouse_btn_t act);
};