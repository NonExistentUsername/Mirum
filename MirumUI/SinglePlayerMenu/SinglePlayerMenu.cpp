/*
 * SinglePlayerMenu.cpp
 *
 *  Created on: 15 ���. 2021 �.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/SinglePlayerMenu.hpp"

SinglePlayerMenu::SinglePlayerMenu() {}

void SinglePlayerMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(processor, states);
}
