#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "struct.h"
#include "main.h"
#include "game.h"

void Initialize(Array_Entity *entities)
{
    sfVector2f scaleBG = {6, 6};

    entities->array[0] = Create_Entity("./layers/parallax-mountain-montain-far.png", entities);
    entities->array[1] = Create_Entity("./layers/parallax-mountain-mountains.png", entities);
    entities->array[2] = Create_Entity("./layers/parallax-mountain-trees.png", entities);

    // for (size_t i = 4; i < 7; i ++)
    // {
    //     entities->array[i] = entities->array[i-4]; // normalement ca marche pas 

    //     float a = sfSprite_getGlobalBounds(entities->array[i-4].sprite).width;
    //     sfVector2f newPos = {a, 0};
    //     entities->array[i-4].position = newPos;
    //     sfSprite_setPosition(entities->array[i-4].sprite, entities->array[i-4].position);

    // }
    

    // Creation player
    entities->array[3] = Create_Entity("./Corvette.png", entities);
    entities->array[3].position.y = 600;
    entities->array[3].position.x = 600;
    sfSprite_setPosition(entities->array[3].sprite, entities->array[3].position);


    entities->array[0].speed = entities->array[3].speed - 0.1;
    entities->array[1].speed = entities->array[3].speed - 0.7;
    entities->array[2].speed = entities->array[3].speed - 1.5;

    // rescale the backgrounds
    for (int i = 0; i < 3; i++)
    {
        entities->array[i].scale = scaleBG;
        sfSprite_setScale(entities->array[i].sprite, entities->array[i].scale);
    }

    // add the update funtction to the background
    for (int i = 0; i < 3; i++)
    {
        entities->array[i].Update = Update_backgrounds;
    }

    entities->array[3].Update = Update_player;
    entities->array[3].speed = 0.1;
}

void Update(struct Entity entities[], sfView *view)
{
    if (keyPressed(sfKeyD))
    {
        sfVector2f newPos = {entities[3].speed, 0};

        sfSprite_move(entities[3].sprite, newPos);
        entities[3].position = sfSprite_getPosition(entities[3].sprite);

        sfSprite_setRotation(entities[3].sprite, 0); //Rotate autour de 0,0 :/

    } else if (keyPressed(sfKeyQ))
    {
        sfVector2f newPos = {- entities[3].speed, 0};

        sfSprite_move(entities[3].sprite, newPos);
        entities[3].position = sfSprite_getPosition(entities[3].sprite);

        sfSprite_setRotation(entities[3].sprite, 180); //Rotate autour de 0,0 :/
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