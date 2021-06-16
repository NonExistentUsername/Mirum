/*
 * PlayButton.cpp
 *
 *  Created on: 15 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/MainMenu.hpp"
#include "../../Includes/MirumUI/SinglePlayerMenu.hpp"

MainMenu::SingleplayerButton::SingleplayerButton() {
	canvas.height = 50;
	canvas.width = 300;

	canvas.left = 1920/2 - canvas.width/2;
	canvas.top = 300;

	texture = TexturesManager::Button;

	text = "Singleplayer";
}

void MainMenu::SingleplayerButton::pressed(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
		texture = TexturesManager::ButtonPressed;
		canvas.height -= 4;
		canvas.top += 4;
	}
}

void MainMenu::SingleplayerButton::unPressed(const sf::Event& event) {
	if(texture.get() == TexturesManager::ButtonPressed.get()) {
		texture = TexturesManager::Button;
		canvas.height += 4;
		canvas.top -= 4;
	}
}

void MainMenu::SingleplayerButton::released(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
		UI::MenuManager::openMenu<SinglePlayerMenu>();
	}
}

MainMenu::SingleplayerButton::~SingleplayerButton() {}
