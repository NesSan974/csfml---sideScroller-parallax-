#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "struct.h"
#include "main.h"

void Update_backgrounds(sfSprite *sprite, sfVector2f *position, float *speed, sfVector2f *scale)
{
    if (keyPressed(sfKeyD))
    {
        sfVector2f move = {*speed , 0};
        sfSprite_move(sprite, move );
        *position = sfSprite_getPosition(sprite);
    }
    if (keyPressed(sfKeyQ))
    {
        sfVector2f move = {- *speed , 0};
        sfSprite_move(sprite, move );
        *position = sfSprite_getPosition(sprite);
    }
}