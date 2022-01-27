#pragma once

template<class T>
class IObservable;

enum Input;

class IInput : public IObservable<Input> {
public:
    virtual void update() = 0;
};