/*
 * drawImage.hpp
 *
 *  Created on: 11 ���. 2021 �.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

void drawImage(sf::RenderTarget& target, sf::RenderStates states, const sf::FloatRect& _scaledCanvas, const std::shared_ptr<sf::Texture> texture);

void drawText(sf::RenderTarget& target, sf::RenderStates states, const sf::FloatRect& _scaledCanvas, const std::string& text);
