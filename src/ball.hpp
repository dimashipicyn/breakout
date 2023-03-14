#pragma once

#include "Node.hpp"
#include "Sprite.h"

class Ball : public NodeBase
{
public:
	virtual ~Ball();

    virtual void init(Game& game) override;
	virtual void update(Game& game) override;

	virtual void render(Game& game) override;

	Sprite ball_;
	float velocity_ = 100.0f;
};
