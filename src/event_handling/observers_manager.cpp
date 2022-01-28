#include "event_handling/observers_manager.hpp"
#include "event_handling/node.hpp"
#include "tools/observer.hpp"
#include "event_handling/key.hpp"

void EventObserversManager::create_head(Observer<const sf::Event&>* observer) {
    first = new EventNode(observer);
    last = first;
}

EventObserverKey EventObserversManager::add(Observer<const sf::Event&>* observer) {
    if(first) {
        last->next = new EventNode(observer);
        last->next->previous = last;
        last = last->next;
    } else {
        create_head(observer);
    }
    return EventObserverKey(this, last);
}

void EventObserversManager::remove_node(EventNode* node) {
    if(node == first) {
        first = first->next;
        first->previous = nullptr;
    } else {
        if(node->previous)
            node->previous->next = node->next;
        if(node->next)
            node->next->previous = node->previous;
    }

    delete node;
}

void EventObserversManager::remove(EventNode* node) {
    if(node == current)
        current_to_delete = true;
    else
        remove_node(node);
}

void EventObserversManager::notify(const sf::Event& event) {
    current = first;
    while(current) {
        current->observer->notify(event);

        if(current_to_delete) {
            remove_node(current);
            current_to_delete = false;
        }

        current = current->next;
    }
}