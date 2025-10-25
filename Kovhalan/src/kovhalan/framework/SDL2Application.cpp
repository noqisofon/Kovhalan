#include "kovhalan/framework/SDL2Application.hxx"
#include "kovhalan/adapters/ICommand.hxx"

namespace kovhalan {
namespace framework {
SDL2Application::SDL2Application() { initializeSDL(); }

SDL2Application::~SDL2Application() { disposeSDL(); }

std::int32_t SDL2Application::run() {
    setupDependencies();

    bool running{ true };
    while ( running ) {
        ::SDL_Event current_event = {};
        while ( ::SDL_PollEvent( &current_event ) ) {
            switch ( current_event.type ) {
            case SDL_QUIT   : running = false; break;

            case SDL_KEYDOWN:
            case SDL_KEYUP  : handleInput( current_event ); break;
            }
        }

        // 状態を更新します。
        // update(deltaTime);

        // 描画します。
        render();
    }

    return 0;
}

bool SDL2Application::initializeSDL() {
    /* サブシステムを全部初期化します。 */
    std::int32_t result = ::SDL_Init( SDL_INIT_EVERYTHING );

    spdlog::info( "SDL_Init result: {}", result );

    assert( result == 0 );

    window_   = drivers::Window::create( "Kovhalan", 800, 600 );

    renderer_ = window_->renderer();

    return result == 0;
}

void SDL2Application::disposeSDL() {
    spdlog::info( "Disposing SDL..." );
    ::SDL_Quit();
    spdlog::info( "Disposed SDL..." );
}

void SDL2Application::handleInput( const SDL_Event &anEvent ) {
    std::shared_ptr<adapters::ICommand> command = input_handler_->handleInput( anEvent );
    if ( command ) {
        // 抽象コマンドを実行します。
        command->execute();
    }
}

void SDL2Application::update( float deltaTime ) {}

void SDL2Application::render() {
    if ( !renderer_ ) {
        return;
    }
    ::SDL_Color background_color{ 0, 0, 0, 255 };

    ::SDL_SetRenderDrawColor( renderer_->nativeRenderer(),
                              background_color.r,
                              background_color.g,
                              background_color.b,
                              background_color.a );

    player_controller_->draw();
    // hud_controller_->draw();

    ::SDL_RenderPresent( renderer_->nativeRenderer() );
}

void SDL2Application::setupDependencies() {}
} // namespace framework
} // namespace kovhalan
