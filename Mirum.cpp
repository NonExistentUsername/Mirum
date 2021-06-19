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

#include "Includes/General/Settings/User.hpp"

#include "Includes/Tools/EventHandler.hpp"
#include "Includes/General/Init.hpp"
#include "Includes/General/EventManager.hpp"
#include "Includes/General/GlobalVariables.hpp"
#include "Includes/General/RenderFrame.hpp"
#include "Includes/General/EventManager.hpp"
#include "Includes/UI/Functions/Drawing.hpp"
#include "Includes/UI/Functions/Scale.hpp"
#include "Includes/UI/UI.hpp"

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

//        sf::Vector2<>
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
