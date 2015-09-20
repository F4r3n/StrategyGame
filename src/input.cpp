#include "input.h"
#include <iostream>

std::map<sf::Mouse::Button, bool> Input::myMouseButtons;
std::map<sf::Keyboard::Key, bool> Input::myKeys;
float Input::myMouseX;
float Input::myMouseY;
Input::Input() {

	//	myKeys = new std::map<sf::Keyboard::Key, bool>();
	//	myMouseButtons = new std::map<sf::Mouse::Button, bool>();
}

Input::~Input() {

}


void Input::update(sf::Event &event) {
	switch (event.type)
	{
		// Key events
		case sf::Event::KeyPressed :  Input::myKeys[event.key.code] = true;  break;
		case sf::Event::KeyReleased : Input::myKeys[event.key.code] = false; break;

									  // Mouse event
		case sf::Event::EventType::MouseButtonPressed :  Input::myMouseButtons[event.mouseButton.button] = true;  break;
		case sf::Event::EventType::MouseButtonReleased : Input::myMouseButtons[event.mouseButton.button] = false; break;

														 // Mouse move event
		case sf::Event::MouseMoved :
														 Input::myMouseX = event.mouseMove.x;
														 Input::myMouseY = event.mouseMove.y;
														 break;

														 // Joystick button events
														 //	case sf::Event::JoyButtonPressed :  myJoystickButtons[event.JoyButton.JoystickId][event.JoyButton.Button] = true;  break;
														 //	case sf::Event::JoyButtonReleased : myJoystickButtons[event.JoyButton.JoystickId][event.JoyButton.Button] = false; break;

														 // Joystick move event
														 //	case sf::Event::JoyMoved :
														 //									myJoystickAxis[event.JoyMove.JoystickId][event.JoyMove.Axis] = event.JoyMove.Position;
														 //									break;

														 // Lost focus event : we must reset all persistent states
		case sf::Event::LostFocus :
														 //ResetStates();
														 break;

		default :
														 break;
	}
}
