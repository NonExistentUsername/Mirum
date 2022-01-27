#pragma once

template<class T>
class IObserver {
public:
    virtual void notify(const T& data) = 0;
};