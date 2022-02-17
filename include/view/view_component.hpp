#pragma once

#include "iview_component.hpp"
#include "view_messages.hpp"
#include "tools/observer.hpp"
#include "ievent_filter.hpp"

class ViewComponent : public IViewComponent {
private:
    using _weak_renderer_ptr = IRenderer*;
    using _unique_observer_ptr = std::unique_ptr<Observer<VMESSAGE>>;
    using _weak_controller_ptr = IEventFilter*;

    ObserversManager<VMESSAGE> manager;
protected:
    ViewComponent(_weak_controller_ptr filter);
    ViewComponent(_weak_controller_ptr filter, Rect<long double> canvas);
    
    void notify_observers(VMESSAGE message);
public:
    void draw(_weak_renderer_ptr renderer) override;

    ObserverKey<VMESSAGE> add(_unique_observer_ptr observer);
    virtual ~ViewComponent();
};