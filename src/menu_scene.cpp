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
    FontPtr font;
    GridPtr grid;

public:
    ~Options() = default;
    void init(Game& game)
    {
        /*auto font = game.resources().get<Font>("EightBits.ttf", 35);
        grid = CreatePtr<Grid>("grid", 200, 200, 2, 4, 200, 30);

        LabelPtr w = CreatePtr<Label>(font, 0, 0, "test", "Difficulty");
        grid->set(0, 0, w);

        SelectPtr ws = CreatePtr<Select>(font, 0, 0, "test");
        ws->add_option("Easy");
        ws->add_option("Medium");
        ws->add_option("Hard");
        grid->set(0, 1, ws);

        LabelPtr ww = CreatePtr<Label>(font, 0, 0, "test", "Language");
        grid->set(1, 0, ww);

        SelectPtr wss = CreatePtr<Select>(font, 0, 0, "test");
        wss->add_option("Russian");
        wss->add_option("English");
        wss->add_option("Germany");
        grid->set(1, 1, wss);

        LabelPtr wsliderlabel = CreatePtr<Label>(font, 0, 0, "test", "Volume");
        grid->set(2, 0, wsliderlabel);

        SliderPtr wslider = CreatePtr<Slider>(font, 0, 0, 100, 5, "test");
        grid->set(2, 1, wslider);

        ButtonPtr back = CreatePtr<Button>(font, 0, 0, "back", "Back");
        back->on(WidgetSignal::LeftClick, [&game]()
            {
            game.pop();
        });
        grid->set(3, 0, back);*/
    }

    void update(Game& game) { /*grid->update(game);*/ }

    void render(Game& game) { /*grid->render(game);*/ }
};

Menu::Menu()
{

}

Menu::~Menu()
{

}

LabelPtr label;
ButtonPtr button;
SliderPtr slider;
SelectPtr select;

void Menu::init(Game& game)
{
    /*auto font = game.resources().get<Font>("EightBits.ttf", 35);

    grid = CreatePtr<Grid>("grid", 50, 50, 1, 2, 200, 30);

    auto start = CreatePtr<Button>(font, 0, 0, "start", "Start");
    start->on(WidgetSignal::LeftClick, [&game]()
        { game.push(CreatePtr<Simple_scene>()); });
    start->on(WidgetSignal::LeftClick, [&game](const Widget&)
        { });
    start->on(WidgetSignal::LeftClick, this, &Menu::click);
    start->on(WidgetSignal::LeftClick, this, &Menu::clickArg);
    grid->set(0, 0, start);

    auto options = CreatePtr<Button>(font, 0, 0, "options", "Options");
    options->on(WidgetSignal::LeftClick, [&game]()
        { game.push(CreatePtr<Options>()); });
    grid->set(1, 0, options);*/
    label = CreatePtr<Label>("Start label");
    button = CreatePtr<Button>("Simple button");
    button->setPos(Point(0, 20));
    slider = CreatePtr<Slider>(0.1f, 0.0f);
    slider->setPos(Point(0, 40));
    slider->setSize(Size(100, 0));
    select = CreatePtr<Select>();
    select->setPos(Point(0, 60));
    select->add_option("First option");
    select->add_option("Second option");
    select->add_option("Another option");
}

void Menu::update(Game& game)
{
    label->update(game);
    button->update(game);
    slider->update(game);
    select->update(game);
}

void Menu::render(Game& game)
{
    label->render(game);
    button->render(game);
    slider->render(game);
    select->render(game);
    //game.get_graphics().debugRenderFont(*font);
}