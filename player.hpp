#pragma once
#include <raylib.h>


struct Player {
    Vector2 position;
    Vector2 velocity;
    float width = 32;
    float height = 32;
    bool onGround = false;
    bool onplatform = false;
};
