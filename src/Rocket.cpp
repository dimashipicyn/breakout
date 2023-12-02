//
//  Rocket.cpp
//  breakout
//
//  Created by Дима Щипицын on 14/03/2023.
//

#include "Rocket.hpp"

#include "game.h"
#include "input.h"

Rocket::~Rocket()
{

}

void Rocket::init(Game &) {
	
}

void Rocket::update(Game& game)
{
	auto x_input = game.get_input().get_horizontal_axis();
	if (x_input) {
		set_direction(glm::vec2(x_input, 0.0f));
		auto oldPos = get_position();
		translate(velocity_ * game.get_elapsed());

		int w = game.get_graphics().get_width();
		auto pos = get_position();
		if (pos.x < 0 || pos.x + get_width() > w)
		{
			set_position(oldPos);
		}
	}
}

