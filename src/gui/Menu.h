#pragma once

#include "Widgets.h"

class Menu : public Widget
{
public:
    Button* newGame = nullptr;
    Button* resume = nullptr;
    Button* options = nullptr;
    Button* exit = nullptr;

    Menu(Widget* parent = nullptr);
};
