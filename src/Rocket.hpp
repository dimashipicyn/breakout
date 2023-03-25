//
//  Rocket.hpp
//  breakout
//
//  Created by Дима Щипицын on 14/03/2023.
//

#ifndef Rocket_hpp
#define Rocket_hpp

#include "SpriteNode.hpp"

class Rocket : public SpriteNode
{
public:
	virtual ~Rocket();

	virtual void init(Game& game) override;
	virtual void update(Game& game) override;

private:
	float velocity_ = 300.0f;
};

#endif /* Rocket_hpp */
