#include "Menu.h"

Menu::Menu(Widget* parent)
    : Widget(parent)
{
    auto* vlayout = new VLayout(this);
    vlayout->move(Point(10, 10));
    vlayout->setMargin(10);

    newGame = new Button("New game");
    vlayout->add(newGame);

    resume = new Button("Resume");
    vlayout->add(resume);

    options = new Button("Options");
    vlayout->add(options);

    exit = new Button("Exit");
    vlayout->add(exit);
}
