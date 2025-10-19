#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"


#define RAYLIB_INCLUDE "raylib-5.5_linux_amd64/include"
#define RAYLIB_LIB "raylib-5.5_linux_amd64/lib"

Cmd cmd = {0};

void common()
{
    cmd_append(&cmd, "cc", "-Wall", "-Wextra");
    cmd_append(&cmd, "-Wpedantic");
}

void raylib()
{
    cmd_append(&cmd, "-I"RAYLIB_INCLUDE);
    cmd_append(&cmd, "-L"RAYLIB_LIB);
    cmd_append(&cmd, "-l:libraylib.a", "-lm");
}

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);
    common();
    cmd_append(&cmd, "-o", "plug", "plug.c");
    raylib();
    if(!cmd_run(&cmd)) return 1;
    return 0;
}
