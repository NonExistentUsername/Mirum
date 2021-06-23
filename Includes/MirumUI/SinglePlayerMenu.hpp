/*
 * SinglePlayer.hpp
 *
 *  Created on: 15 θών. 2021 γ.
 *      Author: mayor
 */


#pragma once
#include "../UI/Functions/Scale.hpp"
#include "../General/TexturesManager.hpp"
#include "../General/MenuManager.hpp"
#include "MainMenu.hpp"
#include <vector>

#include "../Game/GameProcessor.hpp"
#include "../UI/All.hpp"

//class MainMenu;

class SinglePlayerMenu : public UI::Menu {
private:
	Game::Processor processor;

	class ProcessExit {
	private:
		void processExit() {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				UI::MenuManager::openMenu<MainMenu>();
		}
	public:
		ProcessExit() {
			EventManager::frameEvent += MY_METHOD_HANDLER(ProcessExit::processExit);
		}

		~ProcessExit() {
			EventManager::frameEvent -= MY_METHOD_HANDLER(ProcessExit::processExit);
		}
	};

	ProcessExit _pE;
public:
	SinglePlayerMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
