#include "struct.h"
#include "main.h"

#include <SFML/Graphics.h>
#include <SFML/Window.h>

struct Window CreateWindow(sfVector2f scale, char *title)
{
    struct Window window;
    window.videoMode.width = scale.x;
    window.videoMode.height = scale.y;
    window.renderWindow = sfRenderWindow_create(window.videoMode, title, sfClose, NULL);
    
    return window;
}