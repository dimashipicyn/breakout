#include "game.h"

#include "GameLogic.h"

int main(int ac, char** argv, char** env) {
	(void)ac;
	(void)argv;
    (void)env;

	Config config;
	config.width = 800;
	config.heigth = 600;
	config.name = "Breakout";

	Game game(config);
	game.push(CreatePtr<GameLogic>());
    game.run();

    return 0;
}
