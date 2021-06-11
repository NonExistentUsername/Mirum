/*
 * ButtonList.hpp
 *
 *  Created on: 9 ���. 2021 �.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../General/GlobalVariables.hpp"
#include "../../General/TexturesManager.hpp"
#include "../Functions/Scale.hpp"
#include "Button.hpp"
#include "ImageWithText.hpp"
#include "EmptyButton.hpp"

#include <vector>
//#include <string>

namespace UI {
	class ButtonList : public EmptyButton {
	protected:
		ImageWithText image;

		std::vector<std::string> strings;

		bool enabled = false;

		ButtonList(std::unique_ptr<Button> _button);
	public:
	    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	    virtual ~ButtonList();
	};
};
