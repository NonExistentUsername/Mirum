#pragma once

#include <SFML/Graphics.hpp>

template<class T> class Observer;

struct EventNode {
    using EventObserver = Observer<const sf::Event&>;

    EventNode* next = nullptr;
    EventNode* previous = nullptr;

    EventObserver* observer;

    EventNode(EventObserver* observer);
};