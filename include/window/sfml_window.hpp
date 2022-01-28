#pragma once

#include <SFML/Graphics.hpp>
#include "interfaces/window.hpp"

class SFMLRenderer;
class SFMLInputComponent;

class SFMLWindow : public Window {
private:
    sf::RenderWindow* window = nullptr;

    SFMLRenderer* renderer = nullptr;
    SFMLInputComponent* input = nullptr;
public:
    SFMLWindow();

    IRenderer* getRenderer() override;
    IInputComponent* getInput() override;
    
    ~SFMLWindow();
};