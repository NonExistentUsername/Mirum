/*
 * Button.cpp
 *
 *  Created on: 3 ��� 2021 �.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/Button.hpp"
#include "../../Includes/General/EventManager.hpp"
#include "../../Includes/General/Settings.hpp"

#include "../../Includes/UI/Functions/Drawing.hpp"

#include <iostream>

namespace UI {
	Button::Button() {
		EventManager::buttonPressed += MY_METHOD_HANDLER(Button::pressed);
		EventManager::buttonUnPressed += MY_METHOD_HANDLER(Button::unPressed);
		EventManager::buttonReleased += MY_METHOD_HANDLER(Button::released);
	}

	void Button::pressed(const sf::Event& event) {}
	void Button::unPressed(const sf::Event& event) {}
	void Button::released(const sf::Event& event) {}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		sf::FloatRect _scaledCanvas = Scale(canvas);
		drawImage(target, states, _scaledCanvas, texture);
		drawText(target, states, _scaledCanvas, text);
	}

    sf::IntRect Button::getCanvas() const {
    	return canvas;
    }

    std::string Button::getText() const {
    	return text;
    }

    void Button::setCanvas(sf::IntRect canvas) {
    	this->canvas = std::move(canvas);
    }

    void Button::setText(std::string text) {
    	this->text = std::move(text);
    }

	Button::~Button() {
		EventManager::buttonPressed -= MY_METHOD_HANDLER(Button::pressed);
		EventManager::buttonUnPressed -= MY_METHOD_HANDLER(Button::unPressed);
		EventManager::buttonReleased -= MY_METHOD_HANDLER(Button::released);
	}
}
