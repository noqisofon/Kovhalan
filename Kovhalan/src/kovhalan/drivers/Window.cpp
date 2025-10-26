#include "kovhalan/drivers/Renderer.hxx"

#include "kovhalan/drivers/Window.hxx"

namespace kovhalan {
namespace drivers {
Window::Window() : window_{ nullptr }, renderer_{ nullptr } {}

Window::Window( SDL_Window *nativeWindow ) : window_{ nativeWindow }, renderer_{ nullptr } {}

Window::Window( std::string title, std::uint32_t width, std::uint32_t height )
    : Window( ::SDL_CreateWindow( title.c_str(),
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  width,
                                  height,
                                  SDL_WINDOW_OPENGL ) ) {}

Window::~Window() {
    if ( window_ ) {
        ::SDL_DestroyWindow( window_ );
        window_ = nullptr;
    }
}

std::shared_ptr<Window> Window::create( std::string title, std::uint32_t width, std::uint32_t height ) {
    return std::make_shared<Window>( title, width, height );
}

std::shared_ptr<Renderer> Window::renderer() {
    if ( !renderer_ ) {
        renderer_ = std::make_shared<Renderer>( *this );
    }
    return renderer_;
}
} // namespace drivers
} // namespace kovhalan
