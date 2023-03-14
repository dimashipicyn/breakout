//
//  Rocket.hpp
//  breakout
//
//  Created by Дима Щипицын on 14/03/2023.
//

#ifndef Rocket_hpp
#define Rocket_hpp

#include "Node.hpp"
#include "Sprite.h"

class Rocket : public NodeBase
{
public:
	virtual ~Rocket();

	virtual void init(Game& game) override;
	virtual void update(Game& game) override;
	virtual void render(Game& game) override;

	Sprite sprite_;
	float velocity_ = 100.0f;
};

#endif /* Rocket_hpp */
