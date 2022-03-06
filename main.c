#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "struct.h"
#include "main.h"
#include "game.h"

int main(int argc, char const *argv[])
{
    Game *game = malloc(sizeof(Game) + 4 * sizeof(Entity));

    game->entities->size = 10;

    game->Initialize = Initialize;
    game->Update = Update;
    game->Draw = Draw;

    sfVector2f scale = {1920 / 2, 1080 / 2};
    struct Window main_window = CreateWindow(scale, "titre");

    sfView *view = sfView_create();
    sfView_setSize(view, scale);
    sfVector2f vector_Null = {0,0};

    game->Initialize(game->entities->array);

    // game = realloc(game, sizeof(Game) + 5 * sizeof(Entity) ); //marche pas

    while (sfRenderWindow_isOpen(main_window.renderWindow))
    {
        game->Update(game->entities->array, view);

        HandleInput(main_window.renderWindow);

        game->Draw(main_window.renderWindow, game->entities, view);
    }

    return 0;
}
