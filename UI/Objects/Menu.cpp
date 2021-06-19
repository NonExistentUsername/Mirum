/*
 * Menu.cpp
 *
 *  Created on: 2 ���. 2021 �.
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
