/*
 * Init.cpp
 *
 *  Created on: 28 ���. 2021 �.
 *      Author: mayor
 */
#include "../Includes/General/Init.hpp"
#include "../Includes/General/MenuManager.hpp"
#include "../Includes/MirumUI/MainMenu.hpp"
#include "../Includes/General/GlobalVariables.hpp"

sf::RenderWindow createWindow() {
    const sf::Vector2<uint16_t> windowSize = Settings::getWindowSize();
    return sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), Settings::windowName, Settings::getWindowStyle());
}

void reloadWindow() {
	window.close();
    const sf::Vector2<uint16_t> windowSize = Settings::getWindowSize();
	window.create(sf::VideoMode(windowSize.x, windowSize.y), Settings::windowName, Settings::getWindowStyle());
	window.setFramerateLimit(60);
}

void init() {
	UI::MenuManager::openMenu<MainMenu>();
}
