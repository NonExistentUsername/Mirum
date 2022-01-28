#pragma once

class EventObserversManager;
class EventNode;

class EventObserverKey {
private:
    EventObserversManager* manager = nullptr;
    EventNode* node = nullptr;

protected:
    EventObserverKey(EventObserversManager* manager, EventNode* node);

    friend class EventObserversManager;
public:

    void remove();
};