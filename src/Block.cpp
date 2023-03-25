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

void Block::init(Game&)
{
}

void Block::update(Game&)
{

}

void Block::set_type(int type)
{
	solid_ = (type == 1);
}
