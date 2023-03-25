//
//  simple_scene.hpp
//  2dCpp
//
//  Created by Dmitry Shipicyn on 11.09.2022.
//

#ifndef simple_scene_hpp
#define simple_scene_hpp

#include <memory>
#include <vector>

#include "Sprite.h"
#include "AnimationSprite.hpp"
#include "Node.hpp"

#include <glm/vec2.hpp>

class Ball;
class Rocket;
class Block;
class Level;

class Simple_scene : public NodeBase
{
public:
    virtual ~Simple_scene() noexcept;
    virtual void init(Game& game) override;
    virtual void update(Game& game) override;
    
private:

	Ptr<Ball> ball_;
	Ptr<Rocket> rocket_;
	Ptr<Level> level_;
};

#endif /* simple_scene_hpp */
