#pragma once
#include "raylib.h"
#include "player.hpp"
#include "bullets.hpp"
#include <mutex>
#include <vector>

extern Player player;
extern Rectangle ground;
extern Rectangle platform1;
extern std::vector<Bullet> bullets;
extern std::mutex bulletmutex;
extern bool gamerunning;

const int screenWidth = 450;
const int screenHeight = 450;
extern int x;
void bulletspawner();
