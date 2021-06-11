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

#include "Includes/General/Settings.hpp"

#include "Includes/Tools/EventHandler.hpp"
#include "Includes/General/Init.hpp"
#include "Includes/General/EventManager.hpp"
#include "Includes/General/GlobalVariables.hpp"
#include "Includes/General/Defines.hpp"
#include "Includes/General/RenderFrame.hpp"
#include "Includes/General/EventManager.hpp"

#ifdef DEBUG
#include "Includes/Tools/Tests.hpp"
#endif

#include "Includes/UI/Objects/Menu.hpp"

void renderLoop() {
    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            EventManager::processEvent(event);
        }

        renderFrame(window);

        window.display();
    }
}

int main() {
#ifdef DEBUG
	Tests::All();
#endif

	init();
	renderLoop();

	return EXIT_SUCCESS;
}
