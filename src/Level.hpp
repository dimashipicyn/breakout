//
//  Level.hpp
//  breakout
//
//  Created by Дима Щипицын on 16/03/2023.
//

#ifndef Level_hpp
#define Level_hpp

#include "Node.hpp"

class Level : public NodeBase
{
public:
	~Level();
	
	void init(Game& game) override;
	void update(Game& game) override;

private:
	void load_level(Game& game);
	void clear_level();

	int current_level = 0;
};

#endif /* Level_hpp */
