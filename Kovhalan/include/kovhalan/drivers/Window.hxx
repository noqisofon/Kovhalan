#pragma once

#include "kovhalan/kovhalan.hxx"

namespace kovhalan {
namespace drivers {
class Renderer;
class Window {
 protected:
    Window();
    Window( SDL_Window *nativeWindow );
    Window( std::string title, std::uint32_t width, std::uint32_t height );

    Window( const Window & ) = delete;
    Window( Window && )      = delete;

 public:
    ~Window();

 public:
    Window &operator=( const Window & ) = delete;

 public:
    static std::shared_ptr<Window> create( std::string title, std::uint32_t width, std::uint32_t height );
    SDL_Window                    *nativeWindow() const { return window_; }
    std::shared_ptr<Renderer>      renderer();

 private:
    SDL_Window               *window_; //!< Managed SDL2_Window object

    std::shared_ptr<Renderer> renderer_;
};
} // namespace drivers
} // namespace kovhalan
