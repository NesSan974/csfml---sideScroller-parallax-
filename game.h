#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.h>

void Initialize(Array_Entity *);
void Update(struct Entity entities[], sfView *view);
void Draw(sfRenderWindow *window, Array_Entity *entities, sfView *view);


void HandleInput(sfRenderWindow *window);

#endif