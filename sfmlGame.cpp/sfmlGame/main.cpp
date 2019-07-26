#include <TGUI/TGUI.hpp>

// function prototypes 
void buttonHandler();

// window declaration
sf::RenderWindow window{ {300, 300}, "hi ava :)" };
tgui::Gui gui(window); // gui declaration and attachment

// tgui widgets declaration
tgui::Button::Ptr b1 = tgui::Button::create();
tgui::Label::Ptr l1 = tgui::Label::create();

int main() {
	// tgui widgets init
	// button 1
	gui.add(b1);
	b1->setPosition("(parent.size - size) / 2", "75%");
	b1->setSize("75%", "15%");
	b1->setText("click for a suprise!!");
	b1->connect("pressed", buttonHandler);
	// label 1
	gui.add(l1);
	l1->setPosition("(parent.size - size) / 2");
	l1->setSize("50%", "50%");
	l1->setText("<3");
	l1->setTextSize(50);
	l1->setAutoSize(true);
	l1->getRenderer()->setTextColor(tgui::Color::Color(164, 87, 176));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))	{
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
			}
			gui.handleEvent(event); // pass events to widgets
		}
		window.clear();
		gui.draw(); // daw all widgets
		window.display();
	}
}

void buttonHandler() {
	if (int(l1->getTextSize()) == 50) {
		l1->setTextSize(0);
	}
	else {
		l1->setTextSize(50);
	}
}
