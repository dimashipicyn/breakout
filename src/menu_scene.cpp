#include "menu_scene.h"

#include "Common.hpp"
#include "Font.h"
#include "Node.hpp"
#include "Widgets.h"
#include "game.h"
#include "graphics.h"
#include "simple_scene.hpp"

class Options : public NodeBase {
private:
    FontPtr font;
    WidgetGridPtr grid;

public:
    ~Options() = default;
    void init(Game& game)
    {
        Graphics& gr = game.get_graphics();
        font = CreatePtr<Font>();
        font->load(gr, "assets/sans.ttf", 30);

        grid = CreatePtr<WidgetGrid>("grid", 200, 200, 2, 4, 200, 30);

        WidgetLabelPtr w = CreatePtr<WidgetLabel>(font, 0, 0, "test", "Difficulty");
        grid->set(0, 0, w);

        WidgetSelectPtr ws = CreatePtr<WidgetSelect>(font, 0, 0, "test");
        ws->add_option("Easy");
        ws->add_option("Medium");
        ws->add_option("Hard");
        grid->set(0, 1, ws);

        WidgetLabelPtr ww = CreatePtr<WidgetLabel>(font, 0, 0, "test", "Language");
        grid->set(1, 0, ww);

        WidgetSelectPtr wss = CreatePtr<WidgetSelect>(font, 0, 0, "test");
        wss->add_option("Russian");
        wss->add_option("English");
        wss->add_option("Germany");
        grid->set(1, 1, wss);

        WidgetLabelPtr wsliderlabel = CreatePtr<WidgetLabel>(font, 0, 0, "test", "Volume");
        grid->set(2, 0, wsliderlabel);

        WidgetSliderPtr wslider = CreatePtr<WidgetSlider>(font, 0, 0, 100, 5, "test");
        grid->set(2, 1, wslider);

        WidgetButtonPtr back = CreatePtr<WidgetButton>(font, 0, 0, "back", "Back");
        back->on_click([&game](){
            game.pop();
        });
        grid->set(3, 0, back);
    }

    void update(Game& game) { grid->update(game); }

    void render(Game& game) { grid->render(game); }
};

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init(Game& game)
{
    Graphics& gr = game.get_graphics();
    font = CreatePtr<Font>();
    font->load(gr, "assets/sans.ttf", 30);

    grid = CreatePtr<WidgetGrid>("grid", 200, 200, 1, 2, 200, 30);

    auto start = CreatePtr<WidgetButton>(font, 0, 0, "start", "Start");
    start->on_click([&game]() { game.push(CreatePtr<Simple_scene>()); });
    grid->set(0, 0, start);

    auto options = CreatePtr<WidgetButton>(font, 0, 0, "options", "Options");
    options->on_click([&game]() { game.push(CreatePtr<Options>()); });
    grid->set(1, 0, options);
}

void Menu::update(Game& game)
{
    grid->update(game);
}

void Menu::render(Game& game)
{
    grid->render(game);
}