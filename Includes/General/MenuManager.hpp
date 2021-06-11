/*
 * MenuManager.hpp
 *
 *  Created on: 2 апр. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../UI/Objects/Menu.hpp"

namespace UI {
	class MenuManager {
	private:
		static std::unique_ptr<UI::Menu> currentMenu;
	public:

		template<class T>
		static void openMenu() {
			currentMenu.reset(new T());
		}

		static void draw(sf::RenderWindow& window);
	};
}
