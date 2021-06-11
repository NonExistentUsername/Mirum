/*
 * MainMenu.hpp
 *
 *  Created on: 29 мар. 2021 г.
 *      Author: mayor
 */

#pragma once
#include "../UI/Objects/Menu.hpp"
#include "../UI/Objects/Button.hpp"
#include "../UI/Functions/Scale.hpp"
#include "../General/TexturesManager.hpp"
#include "../General/MenuManager.hpp"
#include "SettingsMenu.hpp"

#include <iostream>

class MainMenu : public UI::Menu {
private:
	class ExitButton : public UI::Button {
	private:
		void pressed(const sf::Event& event) override;
		void unPressed(const sf::Event& event) override;
		void released(const sf::Event& event) override;
	public:
		ExitButton();

		~ExitButton();
	};

	class SettingsButton : public UI::Button {
	private:
		void pressed(const sf::Event& event) override;
		void unPressed(const sf::Event& event) override;
		void released(const sf::Event& event) override;
	public:
		SettingsButton();

		~SettingsButton();
	};

	ExitButton exit;
	SettingsButton settingsMenu;
public:
	MainMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
