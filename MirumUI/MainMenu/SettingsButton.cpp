/*
 * SettingsButton.cpp
 *
 *  Created on: 11 ��� 2021 �.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/MainMenu.hpp"

void MainMenu::SettingsButton::pressed(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
		texture = TexturesManager::ButtonPressed;
		canvas.height -= 4;
		canvas.top += 4;
	}
}

void MainMenu::SettingsButton::unPressed(const sf::Event& event) {
	if(texture.get() == TexturesManager::ButtonPressed.get()) {
		texture = TexturesManager::Button;
		canvas.height += 4;
		canvas.top -= 4;
	}
}

void MainMenu::SettingsButton::released(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
		UI::MenuManager::openMenu<SettingsMenu>();
}

MainMenu::SettingsButton::SettingsButton() {
	canvas.height = 50;
	canvas.width = 200;

	canvas.left = 1920/2 - canvas.width/2;
	canvas.top = 500;

	texture = TexturesManager::Button;

	text = "Settings";
}

MainMenu::SettingsButton::~SettingsButton() {
	std::cerr << "MainMenu::SettingsButton deleted" << std::endl;
}
