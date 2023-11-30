#pragma once

#include "Node.hpp"
#include "Widgets.h"
#include "Font.h"

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
    FontPtr font;
    //GridPtr grid;
};