//============================================================================
// Name        : Mirum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Game
//============================================================================

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <memory>
#include <cstdlib>
#include <iomanip>

#include <set>
#include <iostream>
#include <chrono>

#include "Includes/General/Settings/User.hpp"

#include "Includes/Tools/EventHandler.hpp"
#include "Includes/General/Init.hpp"
#include "Includes/General/EventManager.hpp"
#include "Includes/General/GlobalVariables.hpp"
#include "Includes/General/RenderFrame.hpp"
#include "Includes/General/EventManager.hpp"
#include "Includes/UI/All.hpp"
#include "Includes/UI/Functions/Drawing.hpp"
#include "Includes/UI/Functions/Scale.hpp"

#ifdef DEBUG
#include "Includes/Tools/Tests.hpp"
#endif

#include "Includes/UI/Objects/Menu.hpp"

UI::FPS _fps;

void renderLoop() {
    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            EventManager::processEvent(event);
        }
        EventManager::frameEvent();

        _fps.start();

        renderFrame(window);

		window.draw(_fps);

        window.display();
    }
}


int main() {
#ifdef DEBUG
	Tests::All();

	std::cerr << std::fixed;
	std::cerr << std::setprecision(5);
#endif

	init();
	window.setFramerateLimit(60);
	renderLoop();

	return EXIT_SUCCESS;
}
