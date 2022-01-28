#include "event_handling/event_handler.hpp"
#include "event_handling/observers_manager.hpp"
#include "event_handling/key.hpp"

EventHandler::EventHandler(sf::RenderWindow* window):
    window(window) {}

void EventHandler::update() {
    //TODO
}

EventObserverKey EventHandler::addHandler(sf::Event::EventType type, Observer<const sf::Event&>* observer) {
    return managers[type].add(observer);
}