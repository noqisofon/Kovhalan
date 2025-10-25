#pragma once

#include "kovhalan/kovhalan.hxx"

#include "kovhalan/adapters/PlayerController.hxx"
#include "kovhalan/adapters/InputHandler.hxx"
#include "kovhalan/drivers/Window.hxx"
#include "kovhalan/drivers/Renderer.hxx"

namespace kovhalan {
namespace framework {
class SDL2Application {
 public:
    SDL2Application();
    ~SDL2Application();

 public:
    std::int32_t run();

 protected:
    bool initializeSDL();
    void disposeSDL();
    void handleInput( const SDL_Event &anEvent );
    void update( float deltaTime );
    void render();
    void setupDependencies();

 private:
    std::shared_ptr<drivers::Window>            window_;
    std::shared_ptr<drivers::Renderer>          renderer_;
    std::shared_ptr<adapters::PlayerController> player_controller_;
    // std::shared_ptr<adapters::HudController>    hud_controller_;
    std::shared_ptr<adapters::InputHandler>     input_handler_;
};
} // namespace framework
} // namespace kovhalan
