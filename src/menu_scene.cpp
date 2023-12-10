#include "menu_scene.h"

#include "Common.hpp"
#include "Font.h"
#include "Node.hpp"
#include "Widgets.h"
#include "game.h"
#include "graphics.h"
#include "simple_scene.hpp"
#include "Resources.h"

class Options : public Widget {
public:
    Button* back = nullptr;
    Select* difficulty = nullptr;
    Select* language = nullptr;
    Slider* volume = nullptr;

    Options()
    {
        auto* hlayout = new HLayout(this);
        hlayout->setMargin(10);
          
        auto* vlayout = new VLayout;
        hlayout->add(vlayout);
        vlayout->setMargin(10);
        vlayout->add(new Label("Difficulty"));
        vlayout->add(new Label("Language"));
        vlayout->add(new Label("Volume"));
        
        back  = new Button("Back");
        vlayout->add(back);

        vlayout = new VLayout;
        vlayout->setMargin(10);
        hlayout->add(vlayout);
        
        difficulty = new Select;
        vlayout->add(difficulty);
        difficulty->add_option("Easy");
        difficulty->add_option("Medium");
        difficulty->add_option("Hard");

        language = new Select;
        vlayout->add(language);
        language->add_option("Russian");
        language->add_option("English");
        language->add_option("Germany");

        volume = new Slider(0.1f, 0.0f);
        volume->resize(Size(100, 20));
        vlayout->add(volume);
    }
};

void Menu::init(Game& game)
{
    mainMenu_ = CreatePtr<Widget>();
    mainMenu_->move(Point(50, 50));

    options_ = CreatePtr<Options>();
    options_->move(Point(50, 50));
    options_->back->on(WidgetSignal::LeftClick, [this]()
        { active_ = mainMenu_.get(); });

    active_ = mainMenu_.get();

    auto* vlayout = new VLayout(mainMenu_.get());
    vlayout->setMargin(10);
    
    if (!resume_)
    {
        auto* start = new Button("Start");
        vlayout->add(start);
        start->on(WidgetSignal::LeftClick, [&game]()
            { game.push(CreatePtr<Simple_scene>()); });
    }
    else
    {
        auto* resume = new Button("Resume");
        vlayout->add(resume);
        resume->on(WidgetSignal::LeftClick, [&game]()
            { game.pop(); });
    }

    auto* options = new Button("Options");
    vlayout->add(options);
    options->on(WidgetSignal::LeftClick, [this]()
        { active_ = options_.get(); });

    auto* exit = new Button("Exit");
    vlayout->add(exit);
    exit->on(WidgetSignal::LeftClick, [&game]()
        { game.stop(); });
}

void Menu::update(Game& game)
{
    active_->update(game);
}

void Menu::render(Game& game)
{
    active_->render(game);
}