#include "event_handling/node.hpp"

EventNode::EventNode(Observer<const sf::Event&>* observer): 
    observer(observer) {}