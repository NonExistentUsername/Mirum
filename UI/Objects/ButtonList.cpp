/*
 * ButtonList.cpp
 *
 *  Created on: 9 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/ButtonList.hpp"

namespace UI {
	ButtonList::ButtonList(std::unique_ptr<Button> _button) {}

	void ButtonList::draw(sf::RenderTarget& target, sf::RenderStates states) const {
//		target.draw(*button.get());
//
//		if(enabled) {
//			Button copy_button = *button.get();
//			sf::IntRect _canvas = button.get()->getCanvas();
//			int height = button.get()->getCanvas().height;
//			for(const auto& str : strings) {
//				_canvas.top += height;
//				copy_button.setCanvas(_canvas);
//				copy_button.setText(str);
//
//				target.draw(copy_button, states);
//			}
//		}
	}

	ButtonList::~ButtonList() {}
}
