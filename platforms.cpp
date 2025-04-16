
#include "platforms.hpp"

//extern struct Player;
Rectangle platform1;
void init_platforms() {
    
    platform1.x = 100;
    platform1.y = 300; // Example position at the bottom of the window
    platform1.width = 200;
    platform1.height = 32;


}
//bool checkplatform1collisions(Rectangle playerRect, Rectangle platform1) {
//
//    if (CheckCollisionRecs(playerRect, platform1)) {
//        playerRect[1] = platform1.y - player.height;  // Place box on top of platform
//        player.velocity.y = 0;
//        player.onplatform = true;
//    }
//
//    player.onplatform = false;
//    

//}