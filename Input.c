#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "struct.h"
#include "main.h"


void HandleInput(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
    {
        if (event.type == sfEvtClosed)
        {
            sfRenderWindow_close(window);
        }


    }
}

sfBool keyPressed(sfKeyCode keyCode)
{
    return (sfKeyboard_isKeyPressed(keyCode));
}