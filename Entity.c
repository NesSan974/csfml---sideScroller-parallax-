#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "struct.h"
#include "main.h"

Entity Create_Entity(char *_url)
{
    sfVector2f sfVector2f_Null = {0, 0};
    sfVector2f sfVector2f_One = {1, 1};

    Entity e;
    e.sprite = createSprite(_url);
    e.position = sfVector2f_Null;
    e.scale = sfVector2f_One;
    e.speed = 0;

    return e;
}

