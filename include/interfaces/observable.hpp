#pragma once

template<class T>
class IObserver;

template<class T>
class IObservable {
public:
    virtual void add(IObserver<T>* observer) = 0;
    virtual void remove(IObserver<T>* observer)= 0;
    virtual void notify(const T& data) = 0;
};