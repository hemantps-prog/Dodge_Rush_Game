#pragma once
#include "raylib.h"

typedef struct bullet {
	Vector2 pos = {};
	float speed = 5.0f;
	float radius = 5.0f;
}Bullet;