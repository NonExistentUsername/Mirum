/*
 * SettingsMenu.hpp
 *
 *  Created on: 2 апр. 2021 г.
 *      Author: mayor
 */

//#include "MainMenu.hpp"
#pragma once
#include "../UI/UI.hpp"
#include "../UI/Functions/Scale.hpp"
#include "../General/TexturesManager.hpp"
#include <vector>

//class MainMenu;

class SettingsMenu : public UI::Menu {
private:
	class BackButton : public UI::Button {
	private:
		void pressed(const sf::Event& event) override;
		void unPressed(const sf::Event& event) override;
		void released(const sf::Event& event) override;
	public:
		BackButton();
	};

	class ChangeResolutionButtonList : public UI::ButtonList {

	public:
		ChangeResolutionButtonList() {
			canvas.height = 50;
			canvas.width = 100;
			canvas.top = 200;
			canvas.left = 1920/2 - 50;
			text = "test";

			strings = {"1", "2", "3", "ttt"};
		};
	};


	ChangeResolutionButtonList _changeResolution;
	BackButton _back;
public:
	SettingsMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
