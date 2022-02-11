#include "event_handling/event_handler.hpp"
#include "input/iinput_component.hpp"

EventHandler::EventHandler(IInputComponent* input):
    input(input) {}

void EventHandler::notify(const sf::Event& event) {
    manager_for_all_events.notify(event);
    managers[event.type].notify(event);
}

void EventHandler::update() {
    input->handleEvents(this);
}

// using EventObserversManager = ObserversManager<const sf::Event&>;

ObserverKey<const sf::Event&> EventHandler::addHandler(sf::Event::EventType type, std::unique_ptr<Observer<const sf::Event&>> observer) {
    return managers[type].add(std::move(observer));
}

ObserverKey<const sf::Event&> EventHandler::addHandler(std::unique_ptr<Observer<const sf::Event&>> observer) {
    return manager_for_all_events.add(std::move(observer));
}