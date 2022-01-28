#pragma once

template<class T>
class Observer {
public:
    virtual void notify(T message) = 0;
};