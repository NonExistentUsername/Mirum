/*
 * Init.hpp
 *
 *  Created on: 23 мар. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include "../UI/UI.hpp"
#include "Settings.hpp"
#include <memory>

sf::RenderWindow createWindow();
void reloadWindow();

//std::unique_ptr<UI::MenuGraph> loadMenus();

void init();

