#include "ball.hpp"

#include "game.h"
#include "input.h"

Ball::~Ball() {}

void Ball::init(Game &game) {
	Graphics& gr = game.get_graphics();
    ball_.load(gr, "assets/ball.png");

	int width = gr.get_width();
	int height = gr.get_height();

	int min_size = std::min(width, height);
	int size = min_size / 25;

	ball_.set_size(size, size);

	glm::vec2 pos = get_position();
	ball_.set_position(pos.x, pos.y);
}

void Ball::update(Game &game) {
	translate(velocity_ * game.get_tick());

	Graphics& gr = game.get_graphics();

	int width = gr.get_width();
	int height = gr.get_height();

	glm::vec2 pos = get_position();
	glm::vec2 dir = get_direction();

	if (pos.y < 0.0f || pos.y > float(height)) {
		set_direction(glm::vec2(dir.x, -dir.y));
	}

	if (pos.x < 0.0f || pos.x > width) {
		set_direction(glm::vec2(-dir.x, dir.y));
	}
}

void Ball::render(Game &game) {
	glm::vec2 pos = get_position();
	ball_.set_position(pos.x, pos.y);
    ball_.draw(game.get_graphics());
}
