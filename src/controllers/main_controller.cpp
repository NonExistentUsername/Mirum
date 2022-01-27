#include "controllers/main_controller.hpp"
#include "input/interfaces/input_component.hpp"
#include "input/interfaces/event_handler.hpp"

class MyEventHandler : public IEventHandler {
public:
    void handle(const Event& event) override {
        //TODO
    }
};

void MainController::update(IInputComponent* input_component) {
    MyEventHandler ev_handler;
    input_component->handleEvents(&ev_handler);
    //TODO
}

void MainController::draw(IRenderer* renderer) {
    //TODO
}