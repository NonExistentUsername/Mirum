/*
 * MainMenu.cpp
 *
 *  Created on: 3 ��� 2021 �.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/MainMenu.hpp"

MainMenu::MainMenu() {}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(exit, states);
	target.draw(settingsMenu, states);
}
