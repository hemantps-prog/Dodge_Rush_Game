#include "Globals.hpp"

Player player = { {100, 100}, {0, 0} };
Rectangle ground = { 0, 400, 450, 50 };
Rectangle platform1 = { 100, 300, 200, 32 };
int x = 5;
std::vector<bullet> bullets;
bool gamerunning = true;
std::mutex bulletmutex;

Rectangle coin = { 0, (screenHeight - ground.height - 20), 20, 20 };
Color coinColor = GOLD;
int score = 0;
