/*
 * EventManager.cpp
 *
 *  Created on: 2 мая 2021 г.
 *      Author: mayor
 */

#include "../Includes/General/EventManager.hpp"
#include <iostream>

TEvent<const sf::Event&> EventManager::buttonReleased;
TEvent<const sf::Event&> EventManager::buttonPressed;
TEvent<const sf::Event&> EventManager::buttonUnPressed;

void EventManager::processEvent(const sf::Event& event) {
	switch(event.type) {
	case sf::Event::MouseButtonReleased:
		buttonUnPressed(event);
		buttonReleased(event);
	break;
	case sf::Event::MouseButtonPressed:
		buttonPressed(event);
	break;
	default:
	break;
	}
}
