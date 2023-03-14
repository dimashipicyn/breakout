//
//  Block.cpp
//  breakout
//
//  Created by Дима Щипицын on 14/03/2023.
//

#include "Block.hpp"

#include "game.h"

#include "glm/vec2.hpp"

Block::~Block()
{

}

void Block::init(Game& game)
{
	block_.load(game.get_graphics(), "assets/block.png");
}

void Block::render(Game& game)
{
	glm::vec2 pos = get_position();
	block_.set_position(pos.x, pos.y);
	block_.draw(game.get_graphics());
}
