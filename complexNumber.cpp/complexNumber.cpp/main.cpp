/* complexNumber.cpp
Complex number calculator for HCPIII
Jack Margeson 05/2019 */

// inclusions and namespace
#include <SFML/Graphics.hpp>
#include <iostream>
#include "compnum.h"

int main() {
	// window declaration 
	sf::RenderWindow window(sf::VideoMode(300, 200), "Complex Number");
	window.clear(sf::Color::Black);

	// define font
	sf::Font font;
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Font error.\n";
		system("PAUSE");
	}

	// define text
	sf::Text text;
	text.setFont(font);
	text.setString("0.000000+0.000000i");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	// declarations and init
	std::string cn1, cn2, operation, ans;
	int step = 1, ioperation;
	bool val = true;

	std::cout << "Enter complex number #1: ";
	// run the program as long as the window is open
	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::TextEntered:
					if (event.text.unicode < 128) {
						system("CLS");
						switch (step) {
							case 1: // input number 1
								if (event.text.unicode != 13) { // if user does not hit enter
									std::cout << "Enter complex number #1: ";
									cn1 = cn1 + static_cast<char>(event.text.unicode);
									std::cout << cn1;
								}
								else {
									std::cout << "Enter complex number #2: ";
									step = 2;
								}
								break;
							case 2: // input number 2
								if (event.text.unicode != 13) { // if user does not hit enter
									std::cout << "Enter complex number #2: ";
									cn2 = cn2 + static_cast<char>(event.text.unicode);
									std::cout << cn2;
								}
								else {
									std::cout << "Operation (+,-,*): ";
									step = 3;
								}
								break;
							case 3:
								if (event.text.unicode != 13) { // if user does not hit enter
									std::cout << "Operation (+,-,*): ";
									operation = operation + static_cast<char>(event.text.unicode);
									std::cout << operation;
								}
								else {
									std::cout << "Press enter to calculate...";
									step = 4;
								}
								break;
							case 4:
								{
									ioperation = operation[0];
									compnum c1(cn1), c2(cn2), answer;
									switch (ioperation) {
									case 43: answer = c1 + c2; break;
									case 45: answer = c1 - c2; break;
									case 42: answer = c1 * c2; break;
										// case 47: answer = c1 / c2; break;
										// case 94: answer = c1 ^ c2; break;
									default:
										std::cout << "Invalid operation." << std::endl;
										val = false;
										break;
									}
									if (val) {
										text.setString("   " + c1.toString() + "\n" + operation + " " + c2.toString() + "\n" + "---------------\n   " + answer.toString());
										// clear the window with black color
										window.clear(sf::Color::Black);

										// draw everything here...
										// window.draw(...);
										window.draw(text);

										// end the current frame
										window.display();
									}
									std::cout << "Run again? (y/n): ";
									step = 5;
								}
								break;
							case 5:
								if (event.text.unicode != 13) { // if user does not hit enter
									std::cout << "Run again? (y/n): ";
									ans = static_cast<char>(event.text.unicode);
									std::cout << ans;
								}
								else {
									if (ans == "y" || ans == "Y") {
										cn1 = ""; cn2 = ""; operation = "";
										window.clear(sf::Color::Black);
										std::cout << "Enter complex number #1: ";
										step = 1;
									}
									else {
										window.close();
										system("PAUSE");
										return 0;
									}
								}
								break;
						}
					}
					break;
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}
	}

	return 0;
}