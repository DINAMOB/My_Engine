/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** input_mouse
*/

#include "input_mouse.hpp"

InputMouse::InputMouse() {
    this->scroll = 0;
    map_mouse_btn(sf::Mouse::Left, mouse_btn_t::MOUSE_LEFT);
    map_mouse_btn(sf::Mouse::Right, mouse_btn_t::MOUSE_RIGHT);
    map_mouse_btn(sf::Mouse::Middle, mouse_btn_t::MOUSE_MIDDLE);
    map_mouse_btn(sf::Mouse::XButton1, mouse_btn_t::MOUSE_XBUTTON1);
    map_mouse_btn(sf::Mouse::XButton2, mouse_btn_t::MOUSE_XBUTTON2);
}

void InputMouse::map_mouse_btn(sf::Mouse::Button key, mouse_btn_t action) {
    this->mouse_to_action[key] = action;
    this->mouse_state[action] = false;
}

void InputMouse::handle_event(const sf::Event& event)
{
    std::unordered_map<sf::Mouse::Button, mouse_btn_t>::iterator it = this->mouse_to_action.find(event.mouseButton.button);

    if (event.type == sf::Event::MouseButtonPressed && it != this->mouse_to_action.end())
        this->mouse_state[it->second] = true;
    if (event.type == sf::Event::MouseButtonReleased && it != this->mouse_to_action.end())
        this->mouse_state[it->second] = false;
}

bool InputMouse::is_active(mouse_btn_t act) const
{
    std::unordered_map<mouse_btn_t, bool>::const_iterator it = this->mouse_state.find(act);

    return (it != this->mouse_state.end()) ? it->second : false;
}