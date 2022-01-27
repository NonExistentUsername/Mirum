#pragma once

#include <SFML/Graphics.hpp>

#include "interfaces/input_component.hpp"

class SFMLInputComponent : public IInputComponent {
private:
    sf::RenderWindow* window;
protected:
    bool isKeyPressed(KEY_CODE key_code) override;
public:
    SFMLInputComponent(sf::RenderWindow* window);

    void handleEvents(const Command<void(const Event&)>& command) override;
};