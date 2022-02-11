#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "tools/observer.hpp"

class IInputComponent;

class EventHandler : public Observer<const sf::Event&> {
private:
    using _message_type = const sf::Event&;
    using _event_observers_manager = ObserversManager<_message_type>;
    using _event_observer_key = ObserverKey<_message_type>;

    using _unique_observer_ptr = std::unique_ptr<Observer<_message_type>>;
    using _event_type = sf::Event::EventType;

    IInputComponent* input = nullptr;

    std::unordered_map<_event_type, _event_observers_manager> managers;
    _event_observers_manager manager_for_all_events;
protected:
    void notify(_message_type event) override;
public:
    EventHandler(IInputComponent* input);

    void update();

    _event_observer_key addHandler(_event_type type, _unique_observer_ptr observer);
    _event_observer_key addHandler(_unique_observer_ptr observer);
};