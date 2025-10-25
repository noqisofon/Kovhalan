#pragma once

#include "kovhalan/kovhalan.hxx"

#include "kovhalan/adapters/ICommand.hxx"

namespace kovhalan {
namespace adapters {
class InputHandler {
 public:
    using KeyMap = std::map<SDL_Scancode, std::shared_ptr<ICommand>>;

 public:
    InputHandler( KeyMap keyBinds );

 public:
    std::shared_ptr<ICommand> handleInput( const SDL_Event &anEvent );

 private:
    KeyMap key_binds_;
};
} // namespace adapters
} // namespace kovhalan