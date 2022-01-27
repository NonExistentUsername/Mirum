#include "general/app.hpp"
#include "controllers/main_controller.hpp"

int main() {
    Application app;
    app.init(new MainController(&app));
    app.game_loop();
}