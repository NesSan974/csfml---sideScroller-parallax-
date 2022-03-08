#ifndef STRUCT_H
#define STRUCT_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>

typedef struct Window
{
    sfRenderWindow *renderWindow;
    sfVideoMode videoMode;

} window;

typedef struct Circle
{
    sfCircleShape *circleShape;
    sfVector2f position;

} Circle;

typedef struct Entity
{
    sfSprite *sprite;
    sfVector2f position;
    float speed;
    sfVector2f scale;
    void (*Update)(sfSprite *sprite, sfVector2f *position, float *speed, sfVector2f *scale);
    void (*Draw)(sfRenderWindow *);

} Entity;

typedef struct Array_Entity
{
    int size;
    Entity array[];
} Array_Entity;

typedef struct ParalaxBackground
{
    Entity backgroundList[3];
    Entity premierPlan;
    Entity secondPlan;
    Entity troisiemePlan;

} ParalaxBackground;

typedef struct Game
{
    void (*Initialize)();
    void (*Update)();
    void (*Draw)();

    Array_Entity entities;

} Game;

typedef struct Input
{
    sfBool (*IsKeyPressed)(sfKeyCode);

} Input;

#endif