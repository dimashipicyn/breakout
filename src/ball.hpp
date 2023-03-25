#pragma once

#include "SpriteNode.hpp"

class Ball : public SpriteNode
{
public:
	virtual ~Ball();

    virtual void init(Game& game) override;
	virtual void update(Game& game) override;

private:
	float velocity_ = 200.0f;
};
