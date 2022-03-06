#ifndef MAIN_H
#define MAIN_H

#include <SFML/Graphics.h>
#include "struct.h"

struct Window CreateWindow(sfVector2f scale, char *title);
sfSprite *createSprite(char *url);

Entity Create_Entity(char *_url);
Entity Create_player();

sfBool keyPressed(sfKeyCode);

void EntityArrayCopy(Array_Entity _entities, int size, Array_Entity *);

void Update_backgrounds(sfSprite *sprite, sfVector2f *position, float *speed, sfVector2f *scale);

void Update_player(sfSprite *sprite, sfVector2f *position, float *speed, sfVector2f *scale);

#endif