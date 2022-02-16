#pragma once

#include "iview_component.hpp"
#include "event_handling/event_handler.hpp"
#include "tools/observer.hpp"

class ViewObserver : public Observer<const sf::Event&> {
private:
    using _weak_event_handler = EventHandler*;
    using _weak_iview_component = IViewComponent*;

    _weak_iview_component component = nullptr;

    void notify(const sf::Event& message) override;
public:
    ViewObserver(_weak_iview_component component);
};