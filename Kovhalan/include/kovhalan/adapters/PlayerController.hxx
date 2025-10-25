#pragma once

#include "kovhalan/adapters/InputHandler.hxx"
#include "kovhalan/adapters/PlayerMoveCommand.hxx"
#include "kovhalan/adapters/MovePlayerUseCase.hxx"

namespace kovhalan {
namespace adapters {
class PlayerController {
 public:
    PlayerController( std::shared_ptr<MovePlayerUseCase> aPlayerMoveUseCase );

 public:
    InputHandler::KeyMap createKeyBinds();

    void                 draw();

 private:
    std::shared_ptr<MovePlayerUseCase> move_use_case_;
};
} // namespace adapters
} // namespace kovhalan