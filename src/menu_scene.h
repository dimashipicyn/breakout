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
private:
    FontPtr font;
    WidgetGridPtr grid;
};