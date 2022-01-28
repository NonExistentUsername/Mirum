#pragma once

#include <SFML/Graphics.hpp>

template<class T> class Observer;

struct EventNode {
    EventNode* next = nullptr;
    EventNode* previous = nullptr;

    Observer<const sf::Event&>* observer;

    EventNode(Observer<const sf::Event&>* observer);
};