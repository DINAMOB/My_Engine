#include <iostream>
#include "engine_sfml.hpp"
#include "tooltip.hpp"
#include <cmath>

const size_t MEM_SIZE = 6 * 1024;
const int CELL_SIZE = 12;
const int GRID_COLS = 96;
const int GRID_ROWS = MEM_SIZE / GRID_COLS;


using namespace sf;

void scene_menu(Assets& asset, Scene& menu, SceneManager& ma)
{
    AnimatedFrame frame(asset.textures["menu"], {1920, 1080}, 4, 0.5);
    RectButton start(asset.fonts["winXP"], {720, 540}, {400, 180}, "Commencer");
    std::string target_scene = "game";

    start.set_callback([&ma, target_scene]() {
    ma.set_active(target_scene);});
    menu.add(std::make_unique<AnimatedFrame>(frame));
    menu.add(std::make_unique<RectButton>(start));
}

void scene_game(Assets& asset, Scene& game, SceneManager& ma)
{
    RectButton start(asset.fonts["winXP"], {720, 540}, {400, 180}, "Back");
    std::string target_scene = "menu";

    start.set_callback([&ma, target_scene]() {
    ma.set_active(target_scene);});
    game.add(std::make_unique<RectButton>(start));
}

int main(void)
{
    Assets asset("assets.json");
    SceneManager manager;
    RenderEngine engine(VideoMode(1920, 1080, 32), "test", sf::Style::Default, CONTEXT_3D_SETTING);

    scene_menu(asset, manager.create_scene("menu"), manager);
    scene_game(asset, manager.create_scene("game"), manager);
    manager.set_active("menu");
    engine.run(manager);
    return 0;
}
