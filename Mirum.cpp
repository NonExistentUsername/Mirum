//============================================================================
// Name        : Mirum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <memory>
#include <cstdlib>

#include <set>
#include <iostream>
#include <chrono>

#include "Includes/General/Settings.hpp"

#include "Includes/Tools/EventHandler.hpp"
#include "Includes/General/Init.hpp"
#include "Includes/General/EventManager.hpp"
#include "Includes/General/GlobalVariables.hpp"
#include "Includes/General/Defines.hpp"
#include "Includes/General/RenderFrame.hpp"
#include "Includes/General/EventManager.hpp"
#include "Includes/UI/Functions/Drawing.hpp"
#include "Includes/UI/Functions/Scale.hpp"

#ifdef DEBUG
#include "Includes/Tools/Tests.hpp"
#endif

#include "Includes/UI/Objects/Menu.hpp"


std::chrono::steady_clock::time_point start;
sf::Text _fps;

void renderLoop() {
    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            EventManager::processEvent(event);
        }

        start = std::chrono::steady_clock::now();

        renderFrame(window);

        auto dur = std::chrono::steady_clock::now() - start;
    	sf::Text _text;
		_text.setFont(Settings::textFont);
		_text.setCharacterSize(ScaleSize(Settings::fontSize));
		_text.setString(std::to_string(60000000./std::chrono::duration_cast<std::chrono::microseconds>(dur).count()));
		_text.setFillColor(sf::Color::Black);

		sf::Vector2f _canvasCenter = Center(sf::FloatRect(0, 0, 200, 50));
		_text.setPosition(sf::Vector2f(
    				_canvasCenter.x - _text.getLocalBounds().width / 2.,
    				_canvasCenter.y - ScaleSize(Settings::fontSize) / 2.));

		window.draw(_text);

        window.display();
    }
}


int main() {
#ifdef DEBUG
	Tests::All();
#endif

	init();
	window.setFramerateLimit(60);
	renderLoop();

	return EXIT_SUCCESS;
}
