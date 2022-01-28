#include "event_handling/event_handler.hpp"
#include "event_handling/observers_manager.hpp"
#include "event_handling/key.hpp"
#include "input/interfaces/input_component.hpp"

EventHandler::EventHandler(IInputComponent* input):
    input(input) {}

void EventHandler::handle(const sf::Event& event) {
    managers[event.type].notify(event);
}

void EventHandler::update() {
    input->handleEvents(this);
}

EventObserverKey EventHandler::addHandler(sf::Event::EventType type, Observer<const sf::Event&>* observer) {
    return managers[type].add(observer);
}