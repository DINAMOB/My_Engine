/*
** EPITECH PROJECT, 2025
** Engine_sfml
** File description:
** RenderEngine
*/

#include "RenderEngine.hpp"

RenderEngine::RenderEngine(sf::VideoMode mode,
            const std::string& title,
            uint32_t style,
            const sf::ContextSettings& settings)
: window(mode, title, style, settings)
{
    this->window.setFramerateLimit(120);
}

void RenderEngine::clear(const sf::Color color)
{
    this->window.clear(color);
    this->openGL.clear(color);
}

void RenderEngine::dtUpdate(void)
{
    this->dt = this->delta_time.restart().asSeconds();
    this->dt = std::min(this->dt, 0.1f);
}

//         // Matrice de projection
//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         gluPerspective(90.f, 800.f / 600.f, 1.f, 100.f);

//         // Matrice de modèle
//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         glTranslatef(0.f, 0.f, -5.f);

//         // Animation simple (rotation)
//         static float angle = 0.0f;
//         angle += 90.f * deltaTime; // 90° par seconde
//         glRotatef(angle, 0.f, 1.f, 0.f);

//         // Dessin cube
//         glBegin(GL_QUADS);
//         glColor3f(1.f, 0.f, 0.f); glVertex3f(-1.f, -1.f, -1.f);
//         glColor3f(0.f, 1.f, 0.f); glVertex3f(-1.f, 1.f, -1.f);
//         glColor3f(0.f, 0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
//         glColor3f(1.f, 1.f, 0.f); glVertex3f(1.f, -1.f, -1.f);
//         glEnd()
void RenderEngine::run(SceneManager& manager)
{
    float angle = 0.0f;
    float distance = -5;
    while (this->window.isOpen()) {
        this->event.manager(this->window);
        this->dtUpdate();
        this->clear(sf::Color::Black);
                // Matrice de projection
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.f, 800.f / 600.f, 1.f, 100.f);

        // Matrice de modèle
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        if (event.keyboard.is_active(KEY_Q))
            angle += 90.f * this->dt;
        if (event.keyboard.is_active(KEY_D))
            angle += -90.f * this->dt;
        if (event.keyboard.is_active(KEY_Z))
            distance += 1.0f * this->dt;
        if (event.keyboard.is_active(KEY_S))
            distance += -1.0f * this->dt;
        glTranslatef(0.f, 0.f, distance);
        glRotatef(angle, 0.f, 1.f, 0.f);

        // Dessin cube
        glBegin(GL_QUADS);
        glColor3f(1.f, 0.f, 0.f); glVertex3f(-1.f, -1.f, -1.f);
        glColor3f(0.f, 1.f, 0.f); glVertex3f(-1.f, 1.f, -1.f);
        glColor3f(0.f, 0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
        glColor3f(1.f, 1.f, 0.f); glVertex3f(1.f, -1.f, -1.f);
        glEnd();
        if (Scene* scene = manager.get_active()) {
            scene->update(this->window, this->dt);
            scene->draw(this->window);
        }
        this->window.display();
    }
}
