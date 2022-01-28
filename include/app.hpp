#pragma once

class IWindow;
class IController;
class EventHandler;

class Application {
private:
    IWindow* window = nullptr;
    IController* controller = nullptr;
    EventHandler* event_handler = nullptr;

    void update();
    void redraw();
public:
    void init(IWindow* window);
    void game_loop();

    void setController(IController* controller);
    EventHandler* getEventHandler() const;
    void close();

    ~Application();
};