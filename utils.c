
#include <stdio.h>
#include <string.h>
#include <SFML/Graphics.h>

#include "main.h"

sfSprite *createSprite(char *url)
{

    sfSprite *spr = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile(url, NULL);

    sfSprite_setTexture(spr, tex, sfFalse);

    return spr;
}

void EntityArrayCopy(Array_Entity _entities, int size, Array_Entity *new)
{
    for (int i = 0; i < _entities.size - 1; i++)
    {
        new->array[i] = _entities.array[i];
    }
}