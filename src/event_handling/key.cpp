#include "event_handling/key.hpp"
#include "event_handling/observers_manager.hpp"

EventObserverKey::EventObserverKey(EventObserversManager* manager, EventNode* node):
    manager(manager), node(node) {}

void EventObserverKey::remove() {
    this->manager->remove(node);
}