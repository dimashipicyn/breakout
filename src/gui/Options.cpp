#include "Options.h"

Options::Options(Widget* parent)
    : Widget(parent)
{
    auto* hlayout = new HLayout(this);
    hlayout->move(Point(10, 10));
    hlayout->setMargin(10);

    auto* vlayout = new VLayout;
    hlayout->add(vlayout);
    vlayout->setMargin(10);
    vlayout->add(new Label("Difficulty"));
    vlayout->add(new Label("Language"));
    vlayout->add(new Label("Volume"));

    back = new Button("Back");
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