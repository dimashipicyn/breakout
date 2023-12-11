//
//  simple_scene.cpp
//  2dCpp
//
//  Created by Dmitry Shipicyn on 11.09.2022.
//

#include "GameLogic.h"

#include "Block.hpp"
#include "Common.hpp"
#include "Widgets.h"
#include "ball.hpp"
#include "Level.hpp"
#include "Rocket.hpp"

#include "Audio.hpp"
#include "game.h"
#include "graphics.h"
#include "Gui.h"
#include "log.h"
#include "Node.hpp"

#include "gui/Menu.h"
#include "gui/Options.h"

void GameLogic::init(Game& game)
{
    SET_LOG_LEVEL(LOG_LEVEL_INFO);

    initLevel(game);
    initRocket(game);
    initBall(game);
    initGui(game);

    game.get_audio().play_music("../audio/breakout.wav");
}

void GameLogic::update(Game& game)
{

}

void GameLogic::render(Game& game)
{

}


void GameLogic::newGame(Game& game)
{

}

void GameLogic::pause(bool pause)
{
    paused_ = pause;
}


void GameLogic::initBall(Game& game)
{
    int width = game.get_graphics().get_width();
    int height = game.get_graphics().get_height();

    ball_ = CreatePtr<Ball>();
    ball_->load(game.get_graphics(), "../assets/ball.png");
    ball_->set_size(16, 16);

    AABB aabb(width / 2 - 8, height - 16 - rocket_->get_height(), 16, 16);
    Body* ballBody = game.get_physics().create(aabb, true);
    ballBody->set_direction(glm::vec2(0.5f, 0.5f));
    ball_->set_body(ballBody);

    add_node(ball_);
}

void GameLogic::initRocket(Game& game)
{
    int width = game.get_graphics().get_width();
    int height = game.get_graphics().get_height();

    int rSizeW = width / 8;
    int rSizeH = height / 30;
    int x = width / 2 - rSizeW / 2;
    int y = height - rSizeH;
    
    rocket_ = CreatePtr<Rocket>();
    rocket_->load(game.get_graphics(), "../assets/paddle.png");
    rocket_->set_size(rSizeW, rSizeH);

    Body* rocketBody = game.get_physics().create(AABB(x, y, rSizeW, rSizeH));
    rocketBody->set_direction(glm::vec2(1, 0));

    rocket_->set_body(rocketBody);

    add_node(rocket_);
}

void GameLogic::initLevel(Game& game)
{
    int width = game.get_graphics().get_width();
    int height = game.get_graphics().get_height();

    Ptr<SpriteNode> background = CreatePtr<SpriteNode>();
    background->load(game.get_graphics(), "../assets/background.png");
    background->set_size(width, height);
    add_node(background);

    level_ = CreatePtr<Level>();
    add_node(level_);
}

void GameLogic::initGui(Game& game)
{
    int width = game.get_graphics().get_width();
    int height = game.get_graphics().get_height();

    gameGui_ = CreatePtr<Widget>();
    game.gui().add(gameGui_.get());

    menu_ = CreatePtr<Menu>();
    menu_->resize(Size(width, height));
    //menu_->move(Point(10, 10));
    game.gui().add(menu_.get());

    options_ = CreatePtr<Options>();
    options_->resize(Size(width, height));
    //options_->move(Point(10, 10));
    game.gui().add(options_.get());

    gameGui_->setEnabled(false);
    options_->setEnabled(false);

    HLayout* hl = new HLayout(gameGui_.get());
    hl->setMargin(10);

    Button* back = new Button("Back");
    back->move(Point(10, 10));
    back->on(WidgetSignal::LeftClick, [this]
        {
			gameGui_->setEnabled(false);
            menu_->setEnabled(true); 
        });
    hl->add(back);

    menu_->options->on(WidgetSignal::LeftClick, [this] {
        menu_->setEnabled(false);
        options_->setEnabled(true);
    });
    menu_->resume->on(WidgetSignal::LeftClick, [this] {
        menu_->setEnabled(false);
        gameGui_->setEnabled(true);
    });

    options_->back->on(WidgetSignal::LeftClick, [this] {
        options_->setEnabled(false);
        menu_->setEnabled(true);
    });
}
