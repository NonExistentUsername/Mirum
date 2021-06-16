/*
 * Settings.cpp
 *
 *  Created on: 23 мар. 2021 г.
 *      Author: mayor
 */


#include "../Includes/General/Settings.hpp"
#include <iostream>

#include "../Includes/General/Init.hpp"

sf::ContextSettings Settings::contextSettings;

uint32_t Settings::windowStyle = sf::Style::Titlebar | sf::Style::Close;

const sf::Vector2<uint16_t> Settings::defaultWindowSize(1920, 1080);

sf::Vector2<uint16_t> Settings::windowSize(1280, 800);

const uint16_t Settings::fontSize = 20;

const std::string Settings::windowName = "Mirum";

double Settings::kx = (double)windowSize.x / (double)defaultWindowSize.x;
double Settings::ky = (double)windowSize.y / (double)defaultWindowSize.y;

const sf::Font Settings::textFont = []() {
	sf::Font Font;

	if (!Font.loadFromFile("fonts/PressStart2P-Regular.ttf"))
		std::exit(EXIT_FAILURE);

	return Font;
}();

Settings::Settings() {}

const sf::Vector2<uint16_t>& Settings::getWindowSize() {
    return windowSize;
}

const sf::ContextSettings& Settings::getContextSettings() {
	return contextSettings;
}

const uint32_t Settings::getWindowStyle() {
	return windowStyle;
}

const double Settings::Kx() {
	return kx;
}

const double Settings::Ky() {
	return ky;
}

void Settings::changeWindowSize(sf::Vector2<uint16_t> newWindowSize) {
	windowSize = newWindowSize;
    kx = (double)windowSize.x / (double)defaultWindowSize.x;
    ky = (double)windowSize.y / (double)defaultWindowSize.y;
	reloadWindow();
}

Settings::~Settings() {}
