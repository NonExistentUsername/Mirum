/*
 * drawImage.hpp
 *
 *  Created on: 11 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

void drawImage(sf::RenderTarget& target, sf::RenderStates states, const sf::FloatRect& _scaledCanvas, const std::shared_ptr<sf::Texture> texture);

void drawText(sf::RenderTarget& target, sf::RenderStates states, const sf::FloatRect& _scaledCanvas, const std::string& text, const sf::Color& _color);

void drawPoint(sf::RenderTarget& target, sf::RenderStates states, sf::Vector2f _scaledPosition, const float _scaledSize, const sf::Color& _color);

void drawLine(sf::RenderTarget& target, sf::RenderStates states, const sf::Vector2f& _scaledStartPoint, const sf::Vector2f& _scaledEndPoint, const sf::Color& _color);

