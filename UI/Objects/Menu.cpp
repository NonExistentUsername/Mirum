/*
 * Menu.cpp
 *
 *  Created on: 2 апр. 2021 г.
 *      Author: mayor
 */


#include "../../Includes/UI/Objects/Menu.hpp"

#include <iostream>

namespace UI {
	Menu::Menu() {
		#ifdef DEBUG
		std::cerr << "Menu object created\n";
		#endif
	}

	Menu::~Menu() {
		#ifdef DEBUG
		std::cerr << "Menu object deleted\n";
		#endif
	}
}
