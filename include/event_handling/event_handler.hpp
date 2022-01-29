#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "input/ievent_handler.hpp"
#include "observers_manager.hpp"

class EventObserverKey;
class EventObserver;
class IInputComponent;
template<class T> class Observer;

class EventHandler : public IEventHandler {
private:
    IInputComponent* input = nullptr;

    std::map<sf::Event::EventType, EventObserversManager> managers;
protected:
    void handle(const sf::Event& event) override;
public:
    EventHandler(IInputComponent* input);

    void update();

    EventObserverKey addHandler(sf::Event::EventType type, Observer<const sf::Event&>* observer);
};