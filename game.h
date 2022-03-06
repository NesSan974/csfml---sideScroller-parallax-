#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.h>

void Initialize(struct Entity entities[]);
void Update(struct Entity entities[], sfView *view);
void Draw(sfRenderWindow *window, Array_Entity *entities, sfView *view);


void HandleInput(sfRenderWindow *window);

#endif