#include "app.hpp"
#include "controllers/main_controller.hpp"
#include "window/sfml_window.hpp"

int main() {
    Application app;
    auto window = new SFMLWindow();
    app.init(window);
    app.setController(new MainController(&app));
    app.game_loop();
}