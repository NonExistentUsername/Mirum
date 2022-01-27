#pragma once

#include "input/events.hpp"

class IEventHandler {
public:
    virtual void handle(const Event& event) = 0;
};