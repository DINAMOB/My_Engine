/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** events
*/

#pragma once

#include <SFML/Window.hpp>
#include <unordered_map>

typedef enum action {
    KEY_UP,
    KEY_DOWN,
    KEY_RIGHT,
    KEY_LEFT,
    KEY_ENTER,
    KEY_ESCAPE,
    KEY_SPACE,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_LSHIFT,
    KEY_RSHIFT,
    KEY_LCTRL,
    KEY_RCTRL,
    KEY_LALT,
    KEY_RALT,
    KEY_LSUPER,
    KEY_RSUPER,
    KEY_TAB,
    KEY_BACKSPACE,
} action_t;

class InputKeyboard {
public:
    InputKeyboard();
    void handle_event(const sf::Event& event);
    bool is_active(action_t act) const;
private:
    std::unordered_map<sf::Keyboard::Key, action_t> key_to_action;
    std::unordered_map<action_t, bool> key_state;
    void map_key_action(sf::Keyboard::Key key, action_t action);
};

