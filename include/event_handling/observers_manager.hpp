#pragma once

#include <SFML/Graphics.hpp>

class EventNode;
class EventObserverKey;
template<class T> class Observer;

class EventObserversManager {
private:
    EventNode* first = nullptr;
    EventNode* last = nullptr;

    EventNode* current = nullptr;
    bool current_to_delete = false;

    void create_head(Observer<const sf::Event&>* observer);
    void remove_node(EventNode* node);
protected:
    void remove(EventNode* node);

    friend class EventObserverKey;
public:
    EventObserverKey add(Observer<const sf::Event&>* observer);

    void notify(const sf::Event& event);
};