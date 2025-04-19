#include "globals.hpp"
#include "raylib.h"
#include <iostream>


void RespawnCoin(Rectangle& coin, const int &screenWidth,const int& screenHeight) {
    coin.x = (float)GetRandomValue(0, screenWidth - (int)coin.width);
    coin.y = (float)GetRandomValue((screenHeight / 2), (screenHeight/2) + (int)coin.height - platform1.height); // not too close to bottom
}

int main() {
    InitWindow(screenBaseWidth, screenBaseHeight, "Dodge Rush");
    SetTargetFPS(60);


    Rectangle platform1;
    platform1.x = 100;
    platform1.y = 300; // Example position at the bottom of the window
    platform1.width = 200;
    platform1.height = 32;

    std::thread bulletthread(bulletspawner);

    while (!WindowShouldClose()) {
        // Physics
        player.velocity.y += 0.5f; // gravity
        if (IsKeyDown(KEY_RIGHT)) { 
            if (player.position.x == screenWidth-player.width)
                player.velocity.x = 0;
            else
                player.velocity.x = 2; 
        }
        else if (IsKeyDown(KEY_LEFT)) {
            if (player.position.x == 0)
                player.velocity.x = 0;
            else
                player.velocity.x = -2;
        }
        else player.velocity.x = 0;

        if (IsKeyPressed(KEY_SPACE) && (player.onGround || player.onplatform)) {
            std::cout<<"space key is pressed y should decrease\n";
            std::cout <<x<<"\n";
            player.velocity.y = -10;
            player.onGround = false;
        }


        player.position.x += player.velocity.x;
        player.position.y += player.velocity.y;

        //increasing speed 
        std::lock_guard<std::mutex> lock(bulletmutex);
        for (auto& b : bullets) {

            b.pos.y += b.speed;
            if(b.pos.y >=1000.0f)
                b.pos.y = 0;

            if(b.pos.y>=0 && b.pos.y<=450)
                std::cout << "b pos" << b.pos.y << "b speed" << b.speed<< std::endl;
            else
                std::cout << "b pos not in range" << std::endl;
        }

        Rectangle playerRect = { player.position.x, player.position.y, player.width, player.height };

        for (auto& b : bullets) {
            if (CheckCollisionCircleRec(b.pos, b.radius, playerRect)) {
                std::cout << "Player hit!\n";
                // Add death logic here
            }
        }

        // Collision
        if (CheckCollisionRecs(playerRect, ground)==true) {
            player.position.y = ground.y - player.height;
            player.velocity.y = 0;
            player.onGround = true;
        }
        else {
            player.onGround = false;
        }

        // Check collision with platform
        if (CheckCollisionRecs(playerRect, platform1)) {
            player.position.y = platform1.y - player.height;  // Place box on top of platform
            player.velocity.y = 0;
            player.onplatform = true;
        }
        else {
            player.onplatform = false;
        }

        // Coin collision
        if (CheckCollisionRecs(playerRect, coin)) {
            score += 1;
            RespawnCoin(coin, screenWidth, screenHeight);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        //std::lock_guard<std::mutex> lock(bulletmutex);
        for (auto& b : bullets) {
            DrawCircle(static_cast<int>(b.pos.x), static_cast<int>(b.pos.y), b.radius, RED);
        }


        //Drawing Coin
        DrawRectangleRec(coin, coinColor);
        
        //Drawing Score Text
        DrawText(TextFormat("Score: %d", score), 10, screenHeight+15, 20, DARKGRAY);



        DrawRectangleRec(ground, DARKGRAY);
        DrawRectangle(player.position.x, player.position.y, player.width, player.height, BLUE);
        DrawRectangleRec(platform1, GREEN);
        EndDrawing();
    }

    bulletthread.join();
    gamerunning = false;
    

    CloseWindow();
    return 0;
}
