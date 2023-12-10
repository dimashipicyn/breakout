//
//  simple_scene.hpp
//  2dCpp
//
//  Created by Dmitry Shipicyn on 11.09.2022.
//

#ifndef simple_scene_hpp
#define simple_scene_hpp

#include "Node.hpp"

#include <memory>
#include <vector>

class Ball;
class Rocket;
class Level;
class Widget;

class Simple_scene : public NodeBase
{
public:
    virtual void init(Game& game) override;
    
private:

	Ptr<Ball> ball_;
	Ptr<Rocket> rocket_;
	Ptr<Level> level_;
    Ptr<Widget> gui_;
};

#endif /* simple_scene_hpp */
