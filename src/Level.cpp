//
//  Level.cpp
//  breakout
//
//  Created by Дима Щипицын on 16/03/2023.
//

#include "Level.hpp"
#include "Block.hpp"

#include "game.h"
#include "log.h"

#include <fstream>
#include <string>

Level::~Level()
{

}

void Level::init(Game& game)
{
	load_level(game);
}

void Level::update(Game&)
{

}

void Level::load_level(Game& game)
{
	char filename[256] = {0};
	sprintf(filename, "levels/%d.txt", current_level);

	std::ifstream file(filename);
	if (!file.is_open()) {
		LOG_ERROR(std::string("Could not open file") + filename);
		return;
	}

	clear_level();

	Graphics& gr = game.get_graphics();
	Physics& ph = game.get_physics();

	int width = gr.get_width();
	int height = gr.get_height();

	int size_w = 0;
	int size_h = 0;

	file >> size_w >> size_h;

	int b_size_w = width / size_w;
	int b_size_h = height / 2 / size_h;

	for (int i = 0; i < size_h; i++) {
		for (int j = 0; j < size_w; j++) {
			int type = 0;
			file >> type;

			if (type == 0) {
				continue;
			}

			Ptr<Block> block = CreatePtr<Block>();

			if (type == 1) {
				block->load(gr, "assets/block_solid.png");
			}
			else {
				block->load(gr, "assets/block.png");
			}

			block->set_position(glm::vec2(b_size_w * j, b_size_h * i));
			block->set_size(b_size_w, b_size_h);
			block->set_type(type);

			Body* body = ph.create(AABB(b_size_w * j, b_size_h * i, b_size_w, b_size_h));
			body->set_direction(glm::vec2(0, -1.0f));
			body->on_collision([block](auto&, auto&){
				block->delete_node();
			});

			block->set_body(body);

			block->set_color(rand_color);

			add_node(block);
		}
	}
}

void Level::clear_level()
{
	for (int i = 0; i < num_childs(); i++)
	{
		NodePtr child = get_children(i);
		child->delete_node();
	}
}
