#pragma once

#include "Node.hpp"

class Widget;

class Menu : public NodeBase
{
public:
    Menu();
    ~Menu();
    void init(Game& game);
    void update(Game& game);
    void render(Game& game);

    void click() { }
    void clickArg(const Widget&) { }

private:
    Ptr<Widget> widget;
};