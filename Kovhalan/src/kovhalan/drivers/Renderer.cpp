#include "kovhalan/drivers/Texture.hxx"
#include "kovhalan/drivers/Window.hxx"

#include "kovhalan/drivers/Renderer.hxx"

namespace kovhalan {
namespace drivers {
Renderer::Renderer( const Window &window )
    : renderer_{
          ::SDL_CreateRenderer( window.nativeWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) } {}

Renderer::~Renderer() {
    if ( renderer_ ) {
        ::SDL_DestroyRenderer( renderer_ );
        renderer_ = nullptr;
    }
}

Color Renderer::getDrawColor() {
    std::uint8_t r, g, b, a;

    std::int32_t result = ::SDL_GetRenderDrawColor( renderer_, &r, &g, &b, &a );

    assert( result == 0 );

    return Color{ r, g, b, a };
}

std::shared_ptr<Texture> Renderer::getRenderTarget() {
    ::SDL_Texture *render_target{ ::SDL_GetRenderTarget( renderer_ ) };

    if ( !render_target ) {
        return nullptr;
    }
    return std::make_shared<Texture>( render_target );
}

void Renderer::setDrawColor( const Color &color ) {
    std::int32_t result =
        ::SDL_SetRenderDrawColor( renderer_, color.red(), color.green(), color.blue(), color.alpha() );

    assert( result == 0 );
}

void Renderer::setRenderTarget( std::shared_ptr<Texture> aTexture ) {
    if ( !aTexture ) {
        return;
    }

    std::int32_t result = ::SDL_SetRenderTarget( renderer_, aTexture->nativeTexture() );

    assert( result == 0 );
}

void Renderer::clear() { ::SDL_RenderClear( renderer_ ); }

void Renderer::present() { ::SDL_RenderPresent( renderer_ ); }
} // namespace drivers
} // namespace kovhalan
