#pragma once

#include "Node.hpp"

class Widget;
class Options;

class Menu : public NodeBase
{
public:
    Menu(bool resume = false)
        : resume_(resume)
    {
    }
    void init(Game& game);
    void update(Game& game);
    void render(Game& game);

private:
    Ptr<Widget> mainMenu_;
    Ptr<Options> options_;
    Widget* active_ = nullptr;
    bool resume_;
};