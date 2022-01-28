#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

class EventObserverKey;
class EventObserver;
class EventObserversManager;
template<class T> class Observer;

class EventHandler {
private:
    sf::RenderWindow* window = nullptr;

    std::map<sf::Event::EventType, EventObserversManager> managers;
public:
    EventHandler(sf::RenderWindow* window);

    void update();

    EventObserverKey addHandler(sf::Event::EventType type, Observer<const sf::Event&>* observer);
};