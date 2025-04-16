#include <iostream>
#include "player.hpp"

Player player;
void init_player() {
    // Physics
    //Player player = { {100, 100}, {0, 0} };
    player = { {100, 100}, {0, 0} };
    player.velocity.y += 0.5f; // gravity
    if (IsKeyDown(KEY_RIGHT)) {
        if (player.position.x == 450 - player.width)
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
    else 
        player.velocity.x = 0;

    if (IsKeyPressed(KEY_SPACE) && (player.onGround || player.onplatform)) {
        std::cout << "space key is pressed y should decrease\n";
        player.velocity.y = -10;
        player.onGround = false;
    }

    player.position.x += player.velocity.x;
    player.position.y += player.velocity.y;

}

