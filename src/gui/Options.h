#pragma once

#include "Widgets.h"

class Options : public Widget
{
public:
    Button* back = nullptr;
    Select* difficulty = nullptr;
    Select* language = nullptr;
    Slider* volume = nullptr;

    Options(Widget* parent = nullptr);
};
