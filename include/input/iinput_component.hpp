#pragma once

class IEventHandler;

class IInputComponent {
public:
    virtual void handleEvents(IEventHandler* handler) = 0;
};