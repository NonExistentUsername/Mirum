#include "event_handling/node.hpp"

EventNode::EventNode(EventObserver* observer): 
    observer(observer) {}