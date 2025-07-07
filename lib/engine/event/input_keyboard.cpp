/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** input_keyboard
*/

#include "input_keyboard.hpp"

InputKeyboard::InputKeyboard() {
    map_key_action(sf::Keyboard::Up, action_t::KEY_UP);
    map_key_action(sf::Keyboard::Down, action_t::KEY_DOWN);
    map_key_action(sf::Keyboard::Right, action_t::KEY_RIGHT);
    map_key_action(sf::Keyboard::Left, action_t::KEY_LEFT);
    map_key_action(sf::Keyboard::Enter, action_t::KEY_ENTER);
    map_key_action(sf::Keyboard::Escape, action_t::KEY_ESCAPE);
    map_key_action(sf::Keyboard::Space, action_t::KEY_SPACE);
    map_key_action(sf::Keyboard::A, action_t::KEY_A);
    map_key_action(sf::Keyboard::B, action_t::KEY_B);
    map_key_action(sf::Keyboard::C, action_t::KEY_C);
    map_key_action(sf::Keyboard::D, action_t::KEY_D);
    map_key_action(sf::Keyboard::E, action_t::KEY_E);
    map_key_action(sf::Keyboard::F, action_t::KEY_F);
    map_key_action(sf::Keyboard::G, action_t::KEY_G);
    map_key_action(sf::Keyboard::H, action_t::KEY_H);
    map_key_action(sf::Keyboard::I, action_t::KEY_I);
    map_key_action(sf::Keyboard::J, action_t::KEY_J);
    map_key_action(sf::Keyboard::K, action_t::KEY_K);
    map_key_action(sf::Keyboard::L, action_t::KEY_L);
    map_key_action(sf::Keyboard::M, action_t::KEY_M);
    map_key_action(sf::Keyboard::N, action_t::KEY_N);
    map_key_action(sf::Keyboard::O, action_t::KEY_O);
    map_key_action(sf::Keyboard::P, action_t::KEY_P);
    map_key_action(sf::Keyboard::Q, action_t::KEY_Q);
    map_key_action(sf::Keyboard::R, action_t::KEY_R);
    map_key_action(sf::Keyboard::S, action_t::KEY_S);
    map_key_action(sf::Keyboard::T, action_t::KEY_T);
    map_key_action(sf::Keyboard::U, action_t::KEY_U);
    map_key_action(sf::Keyboard::V, action_t::KEY_V);
    map_key_action(sf::Keyboard::W, action_t::KEY_W);
    map_key_action(sf::Keyboard::X, action_t::KEY_X);
    map_key_action(sf::Keyboard::Y, action_t::KEY_Y);
    map_key_action(sf::Keyboard::Z, action_t::KEY_Z);
    map_key_action(sf::Keyboard::F1, action_t::KEY_F1);
    map_key_action(sf::Keyboard::F2, action_t::KEY_F2);
    map_key_action(sf::Keyboard::F3, action_t::KEY_F3);
    map_key_action(sf::Keyboard::F4, action_t::KEY_F4);
    map_key_action(sf::Keyboard::LShift, action_t::KEY_LSHIFT);
    map_key_action(sf::Keyboard::RShift, action_t::KEY_RSHIFT);
    map_key_action(sf::Keyboard::LControl, action_t::KEY_LCTRL);
    map_key_action(sf::Keyboard::RControl, action_t::KEY_RCTRL);
    map_key_action(sf::Keyboard::LAlt, action_t::KEY_LALT);
    map_key_action(sf::Keyboard::RAlt, action_t::KEY_RALT);
    map_key_action(sf::Keyboard::LSystem, action_t::KEY_LSUPER);
    map_key_action(sf::Keyboard::RSystem, action_t::KEY_RSUPER);
    map_key_action(sf::Keyboard::Tab, action_t::KEY_TAB);
    map_key_action(sf::Keyboard::Backspace, action_t::KEY_BACKSPACE);
}

void InputKeyboard::map_key_action(sf::Keyboard::Key key, action_t action) {
    this->key_to_action[key] = action;
    this->key_state[action] = false;
}

void InputKeyboard::handle_event(const sf::Event& event)
{
    std::unordered_map<sf::Keyboard::Key, action_t>::iterator it = this->key_to_action.find(event.key.code);;

    if (event.type == sf::Event::KeyPressed && it != this->key_to_action.end())
        this->key_state[it->second] = true;
    else if (event.type == sf::Event::KeyReleased && it != this->key_to_action.end())
        this->key_state[it->second] = false;
}

bool InputKeyboard::is_active(action_t act) const
{
    std::unordered_map<action_t, bool>::const_iterator it = this->key_state.find(act);

    return (it != this->key_state.end()) ? it->second : false;
}

