#pragma once

#include "icomponent.hpp"
#include "view_messages.hpp"
#include "tools/observer.hpp"

class ViewComponent : public IViewComponent {
private:
    using _weak_renderer_ptr = IRenderer*;
    using _unique_observer_ptr = std::unique_ptr<Observer<VMESSAGE>>;

    ObserversManager<VMESSAGE> manager;
protected:
    ViewComponent();
    ViewComponent(Rect<long double> canvas);

    void notify_observers(VMESSAGE message);
public:
    void draw(_weak_renderer_ptr renderer) override;

    ObserverKey<VMESSAGE> add(_unique_observer_ptr observer);
};