//
//  Level.hpp
//  breakout
//
//  Created by Дима Щипицын on 16/03/2023.
//

#ifndef Level_hpp
#define Level_hpp

#include "Node.hpp"
#include <functional>

class Level : public NodeBase
{
public:
	~Level();
	
	void init(Game& game) override;
	void update(Game& game) override;

private:
	void load_level(Game& game);
	void clear_level();

	using on_change_level_callback = std::function<void(int level_num)>;
	void on_change_level(on_change_level_callback cb);

	on_change_level_callback callback;
	int current_level = 0;
};

#endif /* Level_hpp */
