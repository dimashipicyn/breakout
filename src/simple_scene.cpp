//
//  simple_scene.cpp
//  2dCpp
//
//  Created by Dmitry Shipicyn on 11.09.2022.
//

#include "simple_scene.hpp"
#include "ball.hpp"
#include "Rocket.hpp"
#include "Block.hpp"

#include "game.h"
#include "graphics.h"
#include "Sprite_atlas.hpp"
#include "log.h"
#include "Node.hpp"

#include <glm/vec2.hpp>
#include <cmath>
#include <fstream>

Simple_scene::~Simple_scene() noexcept {
}

struct Level {
	std::vector<int> blocks;
	int size_x;
	int size_y;
	bool load_in_file(const std::string& filename) {
		std::ifstream file(filename);
		if (file.is_open()) {
			blocks.clear();
			file >> size_x;
			file >> size_y;
			while (!file.eof()) {
				int num = -1;
				file >> num;
				if (num != -1) {
					blocks.push_back(num);
				}
			}
			if (blocks.size() == size_x * size_y) {
				return true;
			}
		}
		return false;
	}
};

void Simple_scene::create_walls(int width, int height) {
	/*auto w = get_physic_world();

	physics::AABB walls_aabb[3] = {
		{-20, -20, 20 ,static_cast<float>(height + 20)},
		{static_cast<float>(width), -20, 20, static_cast<float>(height + 20)},
		{0,-20,static_cast<float>(width), 20}
	};

	for (int i = 0; i < 3; i++) {
		auto wall_aabb = walls_aabb[i];
		auto wall_body = std::make_shared<physics::Body>(wall_aabb);
		wall_body->set_active(true);
		wall_body->set_layer(physics::Layer::LAYER_1);

		w->add_body(wall_body, false);
		walls[i] = std::move(wall_body);
	}*/
}

void Simple_scene::load_level(Game& game, int width, int height, int num) {
	/*auto w = get_physic_world();

	Sprite solid;
	Sprite simple;
	solid.load(game.get_graphics(), "assets/block_solid.png");
	simple.load(game.get_graphics(), "assets/block.png");

	Level level;
	level.load_in_file("levels/" + std::to_string(num) + ".txt");

	int x = 0;
	int y = 0;
	int size_x = width / level.size_x;
	int size_y = height / 2 / level.size_y;

	simple.set_size(size_x, size_y);
	solid.set_size(size_x, size_y);

	Color colors[] = {
		{255,0,0},
		{255,255,0},
		{255,0,255},
		{0,255,0},
		{0,255,255},
		{0,0,255}
	};

	for (const auto& b : level.blocks) {
		if (b > 0) {
			bool is_solid = (b == 1);

			Sprite s = (is_solid ? solid : simple);
			s.set_position(x, y);
			s.set_color(colors[b]);

			auto block = std::make_shared<Block>(s);
			auto block_body = std::make_shared<physics::Body>(physics::AABB(x, y, size_x, size_y));

			block_body->set_active(true);
			block_body->set_layer(physics::Layer::LAYER_1);
			block_body->set_owner(block);
			w->add_body(block_body, false);

			block->set_body(block_body);
			block->solid_ = is_solid;

			blocks.emplace_back(std::move(block));
		}

		x += size_x;
		if (x == width) {
			y += size_y;
		}
		x %= width;
	}*/
}

void Simple_scene::create_ball(Game& game, int width, int height) {
	/*auto w = get_physic_world();

	Sprite ball_sprite;
	ball_sprite.load(game.get_graphics(), "assets/ball.png");
	ball_sprite.set_color(Color(0,255,0));

	int min_size = std::min(width, height);
	int rocket_size_h = height / 30;

	int size = min_size / 25;
	int x = width / 2 - size;
	int y = height - rocket_size_h - size / 2;

	ball_sprite.set_size(size, size);
	auto ball = std::make_shared<Ball>(ball_sprite);
	auto ball_body = std::make_shared<physics::Body>(physics::AABB(x, y, size, size));

	ball_body->set_active(true);
	ball_body->set_layer(physics::Layer::LAYER_1);
	ball_body->set_owner(ball);
	w->add_body(ball_body, true);

	ball->set_body(ball_body);

	ball_ = std::move(ball);*/
}

void Simple_scene::create_rocket(Game& game, int width, int height) {
	/*auto w = get_physic_world();

	Sprite rocket_sprite;
	rocket_sprite.load(game.get_graphics(), "assets/paddle.png");

	int size_w = width / 8;
	int size_h = height / 30;
	int x = width / 2 - size_w / 2;
	int y = height - size_h;

	rocket_sprite.set_position(x, y);
	rocket_sprite.set_size(size_w, size_h);
	auto rocket = std::make_shared<Rocket>(rocket_sprite);

	auto rocket_body = std::make_shared<physics::Body>(physics::AABB(x, y, size_w, size_h));

	rocket_body->set_active(true);
	rocket_body->set_layer(physics::Layer::LAYER_1);
	rocket_body->set_owner(rocket);
	w->add_body(rocket_body, true);

	rocket->set_body(rocket_body);

	rocket_ = std::move(rocket);*/
}

glm::vec2 Simple_scene::get_ball_start_pos() {
	//auto rocket_pos = rocket_->get_position();
	//auto rocket_h = rocket_->sprite_.get_height();
	//auto ball_h = ball_->ball_.get_height();
	return glm::vec2();//rocket_pos.x, rocket_pos.y - rocket_h / 2 - ball_h / 2 - 0.1);
}

void Simple_scene::next_level(Game& game) {
	/*auto world = get_physic_world();

	std::for_each(blocks.begin(), blocks.end(), [world](auto& block) {
		world->remove_body(block->get_body());
	});

	blocks.clear();

	current_level++;
	int w = game.get_graphics().get_width();
	int h = game.get_graphics().get_height();
	load_level(game, w, h, current_level);

	ball_->set_velosity(0);
	ball_->set_position(get_ball_start_pos());

	auto rocket_pos = rocket_->get_position();
	rocket_->set_position(Vec2f(w / 2, rocket_pos.y));*/
}

void Simple_scene::start(Game &game) {
	SET_LOG_LEVEL(LOG_LEVEL_INFO);

	//set_physic_world(std::make_unique<physics::World>(1.5));

	/*auto width = game.get_graphics().get_width();
	auto height = game.get_graphics().get_height();

	create_ball(game, width, height);
	create_rocket(game, width, height);

	create_walls(width, height);
	load_level(game, width, height, current_level);*/

	ball_ = CreatePtr<Ball>();
	ball_->set_direction(glm::vec2(0.5f, -0.5f));
	add_node(ball_);

	rocket_ = CreatePtr<Rocket>();
	add_node(rocket_);

	auto width = game.get_graphics().get_width();
	auto height = game.get_graphics().get_height();

	int blocks_w = 10;
	int blocks_h = 5;

	int size_w = width / blocks_w;
	int size_h = height / 2 / blocks_h;

	for (int i = 0; i < blocks_h; i++) {
		for (int j = 0; j < blocks_w; j++) {
			Ptr<Block> block = CreatePtr<Block>();
			block->block_.set_size(size_w, size_h);
			block->set_position(glm::vec2(size_w * j, size_h * i));
			add_node(block);
		}
	}

	game.get_audio().load_music("breakout", "audio/breakout.wav");
	game.get_audio().load_chunk("solid", "audio/solid.wav");

	game.get_audio().play_music("breakout");
}

void Simple_scene::update(Game &game) {
	//Scene::update(game);

	/*if (ball_->get_velosity() == 0) {
		float button = game.get_input().get_button(Input::Button::MouseLeft);
		if (button > 0.1) {
			ball_->set_velosity(0.1);
			ball_->set_direction(Vec2f(0, -1));
		}

		ball_->set_position(get_ball_start_pos());
	}

	auto ball_pos = ball_->get_position();
	int height = game.get_graphics().get_height();
	if (ball_pos.y > height) {
		ball_->set_velosity(0);
		ball_->set_position(get_ball_start_pos());
	}

	for (auto& block : blocks) {
		block->update(game);
	}

	auto w = get_physic_world();
	blocks.erase(std::remove_if(blocks.begin(), blocks.end(), [&w](auto& block) {
		bool has_collision = block->get_body()->has_collision();
		bool is_solid = block->solid_;
		if (has_collision && !is_solid) {
			w->remove_body(block->get_body());
			return true;
		}
		return false;
	}), blocks.end());

	auto found_simple_blocks = std::find_if(blocks.begin(), blocks.end(), [](auto& block) {
		if (!block->solid_) {
			return true;
		}
		return false;
	});
	if (found_simple_blocks == blocks.end()) {
		next_level(game);
	}

	ball_->update(game);
	rocket_->update(game);
	get_physic_world()->step(0);*/

	if (ball_->ball_.is_intersect(rocket_->sprite_)) {
		glm::vec2 dir = ball_->get_direction();
		ball_->set_direction(glm::vec2(dir.x, -dir.y));
	}
}

void Simple_scene::render(Game &game) { 
	//ball_->render(game);
	//rocket_->render(game);

	//for (int i = 0; i < blocks.size(); i++) {
	//	blocks[i]->render(game);
	//}
}

