#pragma once

class IEventHandler;

class IInputComponent {
public:
    virtual void handleEvents(const IEventHandler* handler) = 0;
};