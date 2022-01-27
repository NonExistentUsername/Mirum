#pragma once

#include "input/events.hpp"

class IEventHandler;

class IInputComponent {
protected:
    virtual bool isKeyPressed(KEY_CODE key_code) = 0;

    friend class InputComponentState;
public:
    virtual void handleEvents(const IEventHandler* handler) = 0;
};