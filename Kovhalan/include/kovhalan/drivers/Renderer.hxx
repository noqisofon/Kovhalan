#pragma once

#include "kovhalan/kovhalan.hxx"
#include "kovhalan/drivers/Color.hxx"

namespace kovhalan {
namespace drivers {
class Texture;
class Window;

class Renderer {
 public:
    Renderer( const Window &window );
    Renderer( const Renderer & ) = delete;
    Renderer( Renderer && )      = delete;

    ~Renderer();

 public:
    friend class Window;
    Renderer &operator=( const Renderer & ) = delete;

 public:
    SDL_Renderer            *nativeRenderer() const { return renderer_; }

    Color                    getDrawColor();
    std::shared_ptr<Texture> getRenderTarget();

    void                     setDrawColor( const Color &color );
    void                     setRenderTarget( std::shared_ptr<Texture> aTexture );

    void                     clear();

    void                     present();

 private:
    SDL_Renderer *renderer_; //!< Managed SDL_Renderer object
};
} // namespace drivers
} // namespace kovhalan
