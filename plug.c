#define NOB_IMPLEMENTATION
#include "nob.h"

#include "raylib.h"

#define UI_IMPLEMENTATION
#include "ui.h"

#define BACKGROUND_COLOR "#062329"
#define FOREGROUND_COLOR "#FFFFFF"

int main(void)
{
    const char *path = "plug.c";
    Nob_String_Builder sb = {0};
    if(!nob_read_entire_file(path, &sb)){
        return 1;
    }
    printf("%s\n", sb.items);

    const char *title = "Plug";
    int width = 800;
    int height = 600;
    InitWindow(width, height, title);

    Color bg;
    hex_to_rgb(&bg, BACKGROUND_COLOR);

    const char *font_path = "Iosevka-Regular.ttf";
    Font font = LoadFont(font_path);
    // TODO: Adding line number
    Vector2 line_num_pos = {5, 5};
    Vector2 text_pos;
    int padding = 5;
    text_pos.x = line_num_pos.x + padding;
    text_pos.y = line_num_pos.y + padding;
    SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);

    float font_size  = 40.0f;
    Rectangle cursor = { text_pos.x, text_pos.y , font_size/2 , font_size};

    while(!WindowShouldClose()) {
        if(IsKeyPressed(KEY_LEFT)){
            if (cursor.x > font_size) cursor.x -= font_size/2;
        }
        if(IsKeyPressed(KEY_RIGHT)){
            if (cursor.x < sb.count)cursor.x += font_size/2;
        }

        if(IsKeyPressed(KEY_UP)){
            if (cursor.y > font_size) cursor.y -= font_size;
        }
        if(IsKeyPressed(KEY_DOWN)){
            if (cursor.y < sb.count)cursor.y += font_size;
        }
        BeginDrawing();
        ClearBackground(bg);
        DrawRectangleRec(cursor, BLACK);
        DrawTextEx(font, sb.items, text_pos, font_size, 1.2f, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
