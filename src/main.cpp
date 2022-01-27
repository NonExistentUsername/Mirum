#include "app.hpp"
#include "controllers/main_controller.hpp"
#include "render/sfml_renderer.hpp"
#include "input/sfml_input_component.hpp"

int main() {
    Application app;
    auto renderer = new SFMLRenderer();
    auto input_component = new SFMLInputComponent(renderer);
    app.init(renderer, input_component);
    app.setController(new MainController(&app));
    app.game_loop();
}