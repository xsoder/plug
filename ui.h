#ifndef UI_H
#define UI_H

#include <stddef.h>
#include <stdlib.h>
#include "raylib.h"

#define CONVERT(type, name) (type)strtol(name,NULL,16);
// Function declaration
void hex_to_rgb(struct Color *color, const char *hex);

#ifdef UI_IMPLEMENTATION
void hex_to_rgb(struct Color *color, const char *hex)
{
    // Todo error handeling
    hex++;

    char rHex[3] = {hex[0], hex[1], '\0'};
    char gHex[3] = {hex[2], hex[3], '\0'};
    char bHex[3] = {hex[4], hex[5], '\0'};

    color->r = CONVERT(float, rHex);
    color->g = CONVERT(float, gHex);
    color->b = CONVERT(float, bHex);
}
#endif

#endif
