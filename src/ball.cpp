#include "ball.hpp"

#include "game.h"
#include "input.h"

Ball::~Ball() {}

void Ball::init(Game &) {

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

	velocity_ += 0.001;
}
