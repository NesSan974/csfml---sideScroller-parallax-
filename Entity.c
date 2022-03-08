#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "struct.h"
#include "main.h"


void add_Entity(Array_Entity *ae)
{
    Array_Entity newAE = {ae->size + 1};

    printf("add-entity - size befor add : %d\n", ae->size);
    printf("add-entity - array[0].speed : %.1f\n\n", ae->array[0].speed);

    EntityArrayCopy(*ae, ae->size + 1, &newAE);

    ae = realloc(ae, sizeof(Array_Entity) + sizeof(Entity) * (ae->size +1) );

    EntityArrayCopy(newAE, ae->size, ae);

    printf("add-entity - end function : %d\n", ae->size);
    printf("add-entity - array[0].speed : %.1f\n\n", ae->array[0].speed);


}

Entity Create_Entity(char *_url, Array_Entity *array_entity)
{
    sfVector2f sfVector2f_Null = {0, 0};
    sfVector2f sfVector2f_One = {1, 1};

    Entity e;
    e.sprite = createSprite(_url);
    e.position = sfVector2f_Null;
    e.scale = sfVector2f_One;
    e.speed = 0;

    // add_Entity(array_entity); //marche pas

    // je pense que cest parce que on a pas fais de m/calloc sur array_entity mais sur game.
    // Il faudrait sans dout modifier TOUT game alloc, ou juste separé la variable entities de game.

    return e;
}
