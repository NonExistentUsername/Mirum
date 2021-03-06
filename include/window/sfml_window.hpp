#pragma once

#include <SFML/Graphics.hpp>
#include "iwindow.hpp"

class SFMLRenderer;
class SFMLInputComponent;

class SFMLWindow : public IWindow {
private:
    sf::RenderWindow* window = nullptr;

    SFMLRenderer* renderer = nullptr;
    SFMLInputComponent* input = nullptr;
public:
    SFMLWindow();

    IRenderer* getRenderer() override;
    IInputComponent* getInput() override;

    bool is_opened() override;
    void close() override;

    ~SFMLWindow();
};