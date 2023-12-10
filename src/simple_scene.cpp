//
//  simple_scene.cpp
//  2dCpp
//
//  Created by Dmitry Shipicyn on 11.09.2022.
//

#include "simple_scene.hpp"
#include "Block.hpp"
#include "Level.hpp"
#include "Rocket.hpp"
#include "ball.hpp"
#include "menu_scene.h"

#include "Common.hpp"
#include "Widgets.h"
#include "Audio.hpp"
#include "Node.hpp"
#include "Sprite_atlas.hpp"
#include "game.h"
#include "graphics.h"
#include "input.h"
#include "log.h"
#include "Gui.h"


#include <cmath>
#include <fstream>
#include <glm/vec2.hpp>


void Simple_scene::init(Game& game)
{
    SET_LOG_LEVEL(LOG_LEVEL_INFO);

    Physics& physics = game.get_physics();
    Graphics& gr = game.get_graphics();

    int width = gr.get_width();
    int height = gr.get_height();

    Ptr<SpriteNode> background = CreatePtr<SpriteNode>();
    background->load(gr, "../assets/background.png");
    background->set_size(width, height);
    add_node(background);

    level_ = CreatePtr<Level>();
    add_node(level_);

    ball_ = CreatePtr<Ball>();
    ball_->load(game.get_graphics(), "../assets/ball.png");
    ball_->set_size(10, 10);

    Body* ball_body = physics.create(AABB(400, 550, 10, 10), true);
    ball_body->set_direction(glm::vec2(0.5f, 0.5f));
    ball_->set_body(ball_body);

    add_node(ball_);

    int r_size_w = width / 8;
    int r_size_h = height / 30;
    int x = width / 2 - r_size_w / 2;
    int y = height - r_size_h;

    rocket_ = CreatePtr<Rocket>();
    rocket_->load(gr, "../assets/paddle.png");
    rocket_->set_size(r_size_w, r_size_h);

    Body* rocket_body = physics.create(AABB(x, y, r_size_w, r_size_h));
    rocket_body->set_direction(glm::vec2(1, 0));

    rocket_->set_body(rocket_body);

    add_node(rocket_);

    game.get_audio().play_music("../audio/breakout.wav");

    gui_ = CreatePtr<Widget>();
    game.gui().add(gui_.get());
    Button* back = new Button("Back", gui_.get());
    back->move(Point(10, 10));
    back->on(WidgetSignal::LeftClick, [&game, this]
        {
			gui_->setEnabled(false);
			game.push(CreatePtr<Menu>(true));
        });
}
