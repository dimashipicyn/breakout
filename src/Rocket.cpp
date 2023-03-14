//
//  Rocket.cpp
//  breakout
//
//  Created by Дима Щипицын on 14/03/2023.
//

#include "Rocket.hpp"

#include "game.h"

Rocket::~Rocket()
{

}

void Rocket::init(Game &game) {
	Graphics& gr = game.get_graphics();
	sprite_.load(gr, "assets/paddle.png");

	int width = gr.get_width();
	int height = gr.get_height();

	int size_w = width / 8;
	int size_h = height / 30;
	int x = width / 2 - size_w / 2;
	int y = height - size_h;

	set_position(glm::vec2(x, y));
	sprite_.set_position(x, y);
	sprite_.set_size(size_w, size_h);
}

void Rocket::update(Game& game)
{
	auto x_input = game.get_input().get_horizontal_axis();
	if (x_input) {
		set_direction(glm::vec2(x_input, 0.0f));
		//velocity_ = 0.5f;
		translate(velocity_ * game.get_tick());
	}
//	else {
//		set_direction(glm::vec2(0, 0));
//		//velocity_ = 0.0f;
//	}
}

void Rocket::render(Game& game)
{
	/*auto pos = get_position();
	 auto dir = get_direction();
	 pos = pos.add(dir.scalar(game.get_lag() * get_velosity()));
	 int x = pos.x - sprite_.get_width() / 2;
	 int y = pos.y - sprite_.get_height() / 2;*/
	glm::vec2 pos = get_position();
	sprite_.set_position(pos.x, pos.y);
	sprite_.draw(game.get_graphics());
}

