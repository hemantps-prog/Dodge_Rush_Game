#include <iostream>
#include <chrono>
#include <cstdlib>
//#include "bullets.hpp"
#include "globals.hpp"

void bulletspawner() {
	while (gamerunning) {
		Bullet b;
		b.pos = {static_cast<float>(rand()% screenWidth),0.0f};

		{
			std::lock_guard<std::mutex> lock(bulletmutex);
			bullets.push_back(b);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	}
}