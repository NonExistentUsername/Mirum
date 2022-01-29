#pragma once

#include <SFML/Graphics.hpp>
#include "key.hpp"

class EventNode;
class EventObserverKey;
template<class T> class Observer;

class EventObserversManager {
private:
    using node_ptr = EventNode*;

    node_ptr first = nullptr;
    node_ptr last = nullptr;

    node_ptr current = nullptr;
    bool current_to_delete = false;

    void create_head(Observer<const sf::Event&>* observer);
    void remove_node(node_ptr node);
protected:
    void remove(node_ptr node);

    friend class EventObserverKey;
public:
    EventObserverKey add(Observer<const sf::Event&>* observer);

    void notify(const sf::Event& event);
};