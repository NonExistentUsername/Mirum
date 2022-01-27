#pragma once

#include "command.hpp"
#include "input/events.hpp"

class IInputComponent {
protected:
    virtual bool isKeyPressed(KEY_CODE key_code) = 0;

    friend class InputComponentState;
public:
    virtual void handleEvents(const Command<void(const Event&)>& command) = 0;
};