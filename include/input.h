#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <map>
class Input {
	public:
		Input();
		~Input();
		void update(sf::Event &event);
		bool isMouseLeftPressed();
		static std::map<sf::Mouse::Button, bool> myMouseButtons;
		static std::map<sf::Keyboard::Key, bool> myKeys;
	private:
		static float myMouseX;
		static float myMouseY;

};

#endif
