#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <map>
class Input {
	public:
		Input();
		~Input();
		void update(sf::Event &event);
		static bool isMousePressed(sf::Mouse::Button button);
		static std::map<std::string, bool> actionsClick;
	private:
		static float myMouseX;
		static float myMouseY;
		static std::map<sf::Mouse::Button, bool> myMouseButtons;
		static std::map<sf::Keyboard::Key, bool> myKeys;

};

#endif
