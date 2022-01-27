#pragma once

#include "interfaces/input_component.hpp"

class InputComponentState {
private:
    IInputComponent* input_component;
public:
    InputComponentState(IInputComponent* input_component): input_component(input_component) {}

    bool isKeyPressed(KEY_CODE key_code) {
        return input_component->isKeyPressed(key_code);
    }
};