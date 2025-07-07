/*
** EPITECH PROJECT, 2025
** Engine_sfml
** File description:
** RenderOpenGL
*/

#include "RenderOpenGL.hpp"

//  // Nettoyage
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//         glClearColor(0.f, 0.f, 0.f, 1.f); // fond noir

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
//         glEnd();

RenderOpenGL::RenderOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.f);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.f, 0.f, 0.f, 1.f);
}

void RenderOpenGL::clear(sf::Color color)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(color.r, color.g, color.b, color.a);
}
