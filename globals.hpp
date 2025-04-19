#pragma once
#include "raylib.h"
#include "player.hpp"
#include "bullets.hpp"
//#include "coin.hpp"
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
const int screenBaseWidth = 600;
const int screenBaseHeight = 600;
extern int x;
void bulletspawner();

extern Rectangle coin;
extern Color coinColor;
extern int score;

//adding coins declarations
//extern Coin coin;
//extern int score;
//extern bool coincollected = false;


