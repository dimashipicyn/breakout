#include "Common.hpp"
#include "game.h"
#include "menu_scene.h"
#include "simple_scene.hpp"

int main(int ac, char** argv, char** env) {
	(void)ac;
	(void)argv;
    (void)env;

	Config config;
	config.width = 800;
	config.heigth = 600;
	config.name = "Breakout";

	Game game(config);
	game.push(CreatePtr<Simple_scene>());
    game.run();

    return 0;
}
