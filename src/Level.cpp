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

void Level::update(Game& game)
{
	bool level_end = true;

	for (int i = 0; i < num_childs(); i++) {
		Block* block = (Block*)get_children(i).get();
		if (block->get_type() != Block::SOLID)
		{
			level_end = false;
			break;
		}
	}


	if (level_end)
	{
		++current_level;
		load_level(game);
		if (callback)
			callback(current_level);
	}
}

void Level::load_level(Game& game)
{
	char filename[256] = {0};
	sprintf(filename, "../levels/%d.txt", current_level);

	std::ifstream file(filename);
	if (!file.is_open()) {
		LOG_ERROR(std::string("Could not open file: ") + filename);
		game.stop();
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

			if ((Block::Type)type == Block::SOLID) {
				block->load(gr, "../assets/block_solid.png");
			}
			else {
				block->load(gr, "../assets/block.png");
			}

			block->set_position(glm::vec2(b_size_w * j, b_size_h * i));
			block->set_size(b_size_w, b_size_h);
			block->set_type((Block::Type)type);

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

void Level::on_change_level(on_change_level_callback cb)
{
	callback = cb;
}
