#pragma once

#include "SpriteNode.hpp"

class Ball : public SpriteNode
{
public:
	virtual ~Ball();

    virtual void init(Game& game) override;
	virtual void update(Game& game) override;
	float velocity_ = 0.0f;
};
