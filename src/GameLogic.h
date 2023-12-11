//
//  simple_scene.hpp
//  2dCpp
//
//  Created by Dmitry Shipicyn on 11.09.2022.
//

#ifndef simple_scene_hpp
#define simple_scene_hpp

#include "Node.hpp"

#include <memory>
#include <vector>

class Game;
class Ball;
class Rocket;
class Level;
class Widget;
class Menu;
class Options;

class GameLogic : public NodeBase
{
public:
    void init(Game& game) override;
    void update(Game& game) override;
    void render(Game& game) override;
	void newGame(Game& game);
	void pause(bool pause);

private:
	void initBall(Game& game);
	void initRocket(Game& game);
	void initLevel(Game& game);
	void initGui(Game& game);
private:
	Ptr<Ball> ball_;
	Ptr<Rocket> rocket_;
	Ptr<Level> level_;
    Ptr<Widget> gameGui_;
    Ptr<Menu> menu_;
    Ptr<Options> options_;

	bool paused_ = true;
};

#endif /* simple_scene_hpp */
