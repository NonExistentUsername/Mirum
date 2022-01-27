#pragma once

#include <SFML/Graphics.hpp>

#include "interfaces/input_component.hpp"

class IEventHandler;
class SFMLRenderer;

class SFMLInputComponent : public IInputComponent {
private:
    sf::RenderWindow* window;
protected:
    bool isKeyPressed(KEY_CODE key_code) override;
public:
    SFMLInputComponent(const SFMLRenderer* const renderer);

    void handleEvents(const IEventHandler* command) override;
};