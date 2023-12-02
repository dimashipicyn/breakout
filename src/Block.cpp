//
//  Block.cpp
//  breakout
//
//  Created by Дима Щипицын on 14/03/2023.
//

#include "Block.hpp"

#include "game.h"
#include "Audio.hpp"

#include "glm/ext/vector_float2.hpp"
#include "glm/vec2.hpp"
#include "physics.h"

Block::~Block()
{

}

void Block::init(Game& game)
{
	Physics& ph = game.get_physics();

	glm::vec2 pos = get_position();

	Body *body = ph.create(AABB(pos.x, pos.y, get_width(), get_height()));
	body->set_direction(glm::vec2(0, -1.0f));
	body->on_collision([this, &game](auto &, auto &) {
		if (type_ != SOLID)
			delete_node();
		game.get_audio().play_chunk("solid");
	});

	set_body(body);
}

void Block::update(Game&)
{
}

void Block::set_type(Type type)
{
	type_ = type;
}

Block::Type Block::get_type()
{
	return type_;
}
