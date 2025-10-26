#include "kovhalan/adapters/InputHandler.hxx"

namespace kovhalan {
namespace adapters {
InputHandler::InputHandler( KeyMap hudKeyBinds ) : key_binds_{ hudKeyBinds } {}

std::shared_ptr<ICommand> InputHandler::handleInput( const SDL_Event &anEvent ) {
    if ( anEvent.type != SDL_KEYDOWN ) {
        return nullptr;
    }

    SDL_Scancode key = anEvent.key.keysym.scancode;
    if ( key_binds_.count( key ) ) {
        // プレイヤーが動ける状態ならプレイヤー入力を優先します。
        return key_binds_.at( key );
    }
    // if ( hud_key_binds_.count( key ) ) {
    //     return hud_key_binds_.at( key );
    // }

    return nullptr;
}
} // namespace adapters
} // namespace kovhalan
