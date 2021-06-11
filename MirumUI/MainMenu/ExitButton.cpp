/*
 * ExitButton.cpp
 *
 *  Created on: 11 мая 2021 г.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/MainMenu.hpp"

MainMenu::ExitButton::ExitButton() {
	canvas.height = 50;
	canvas.width = 200;

	canvas.left = 1920/2 - canvas.width/2;
	canvas.top = 600;

	texture = TexturesManager::Button;

	text = "Exit";
}

void MainMenu::ExitButton::pressed(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
		texture = TexturesManager::ButtonPressed;
		canvas.height -= 4;
		canvas.top += 4;
	}
}

void MainMenu::ExitButton::unPressed(const sf::Event& event) {
	if(texture.get() == TexturesManager::ButtonPressed.get()) {
		texture = TexturesManager::Button;
		canvas.height += 4;
		canvas.top -= 4;
	}
}

void MainMenu::ExitButton::released(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
		std::cerr << "Exiting.." << std::endl;
		std::exit(EXIT_SUCCESS);
	}
}

MainMenu::ExitButton::~ExitButton() {
	std::cerr << "MainMenu::ExitButton deleted" << std::endl;
}
