//
//  Block.hpp
//  breakout
//
//  Created by Дима Щипицын on 14/03/2023.
//

#ifndef Block_hpp
#define Block_hpp

#include "Node.hpp"
#include "Sprite.h"

class Block : public NodeBase
{
public:
	virtual ~Block();

	virtual void init(Game& game) override;
	virtual void render(Game& game) override;

	Sprite block_;
	bool solid_ = false;
};


#endif /* Block_hpp */
