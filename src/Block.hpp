//
//  Block.hpp
//  breakout
//
//  Created by Дима Щипицын on 14/03/2023.
//

#ifndef Block_hpp
#define Block_hpp

#include "SpriteNode.hpp"

class Block : public SpriteNode
{
public:
	enum Type {
		SIMPLE,
		SOLID
	};

public:
	virtual ~Block();

	virtual void init(Game& game) override;
	virtual void update(Game& game) override;

	void set_type(Type type);
	Type get_type();

private:
	Type type_ = SIMPLE;
};


#endif /* Block_hpp */
