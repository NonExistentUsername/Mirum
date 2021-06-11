/*
 * Init.cpp
 *
 *  Created on: 28 мар. 2021 г.
 *      Author: mayor
 */
#include "../Includes/General/Init.hpp"
#include "../Includes/General/MenuManager.hpp"
#include "../Includes/MirumUI/MainMenu.hpp"

sf::RenderWindow createWindow() {
    const sf::Vector2<uint16_t> windowSize = Settings::getWindowSize();
    return sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), Settings::windowName, Settings::getWindowStyle());
}

void init() {
	UI::MenuManager::openMenu<MainMenu>();
}
