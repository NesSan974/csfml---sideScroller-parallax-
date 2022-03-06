#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "struct.h"
#include "main.h"
#include "game.h"

void Initialize(struct Entity entities[])
{
    sfVector2f scaleBG = {6, 6};

    entities[0] = Create_Entity("./layers/parallax-mountain-montain-far.png");
    entities[1] = Create_Entity("./layers/parallax-mountain-mountains.png");
    entities[2] = Create_Entity("./layers/parallax-mountain-trees.png");

    // Creation player
    entities[3] = Create_Entity("./Corvette.png");
    entities[3].position.y = 600;
    sfSprite_setPosition(entities[3].sprite, entities[3].position);


    entities[0].speed = entities[3].speed - 0.1;
    entities[1].speed = entities[3].speed - 0.7;
    entities[2].speed = entities[3].speed - 1.5;

    // rescale the backgrounds
    for (int i = 0; i < 3; i++)
    {
        entities[i].scale = scaleBG;
        sfSprite_setScale(entities[i].sprite, entities[i].scale);
    }

    // add the update funtction to the background
    for (int i = 0; i < 3; i++)
    {

        entities[i].Update = Update_backgrounds;
    }

    entities[3].Update = Update_player;
    entities[3].speed = 0.1;
}

void Update(struct Entity entities[], sfView *view)
{

    if (keyPressed(sfKeyD))
    {
        sfVector2f newPos = {entities[3].speed, 0};

        sfSprite_move(entities[3].sprite, newPos);
        entities[3].position = sfSprite_getPosition(entities[3].sprite);
    }
    sfView_setCenter(view, entities[3].position);

    for (size_t i = 0; i < 3; i++)
    {
        entities[i].Update(entities[i].sprite, &entities[i].position, &entities[i].speed, &entities[i].scale);
    }

}

void Draw(sfRenderWindow *window, Array_Entity *entities, sfView *view)
{

    sfRenderWindow_clear(window, sfColor_fromRGB(145, 21, 48));

    for (int i = 0; i < 4; i++)
    {
        sfRenderWindow_drawSprite(window, entities->array[i].sprite, NULL);
    }

    sfRenderWindow_setView(window, view);
    sfRenderWindow_display(window);
}