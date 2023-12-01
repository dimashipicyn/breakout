#include "menu_scene.h"

#include "Common.hpp"
#include "Font.h"
#include "Node.hpp"
#include "Widgets.h"
#include "game.h"
#include "graphics.h"
#include "simple_scene.hpp"
#include "Resources.h"

class Options : public NodeBase {
private:
    WidgetPtr widget;

public:
    ~Options() = default;
    void init(Game& game)
    {
        widget = CreatePtr<Widget>();
        widget->setPos(Point(100, 100));
        auto hlayout = new HLayout(widget.get());
        hlayout->setSpacing(Size(10, 10));
        auto vlayout = new VLayout(hlayout);
        vlayout->setSpacing(Size(10, 10));
        vlayout->add(new Label("Difficulty"));
        vlayout->add(new Label("Language"));
        vlayout->add(new Label("Volume"));
        
        auto back = new Button("Back", vlayout);
        back->on(WidgetSignal::LeftClick, [&game]()
            { game.pop(); });

        vlayout = new VLayout(hlayout);
        vlayout->setSpacing(Size(10, 10));
        auto select = new Select(vlayout);
        select->add_option("Easy");
        select->add_option("Medium");
        select->add_option("Hard");

        select = new Select(vlayout);
        select->add_option("Russian");
        select->add_option("English");
        select->add_option("Germany");

        auto slider = new Slider(0.1f, 0.0f, widget.get());
    }

    void update(Game& game) { widget->update(game); }

    void render(Game& game) { widget->render(game); }
};

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init(Game& game)
{
    widget = CreatePtr<Widget>();

    auto vlayout = new VLayout(widget.get());
    vlayout->setSpacing(Size(10, 10));
    auto start = new Button("Start", vlayout);
    start->on(WidgetSignal::LeftClick, [&game]()
        { game.push(CreatePtr<Simple_scene>()); });

    auto options = new Button("Options", vlayout);
    options->on(WidgetSignal::LeftClick, [&game]()
        { game.push(CreatePtr<Options>()); });

    auto exit = new Button("Exit", vlayout);
    exit->on(WidgetSignal::LeftClick, [&game]()
        { game.stop(); });
}

void Menu::update(Game& game)
{
    widget->update(game);
}

void Menu::render(Game& game)
{
    widget->render(game);
}