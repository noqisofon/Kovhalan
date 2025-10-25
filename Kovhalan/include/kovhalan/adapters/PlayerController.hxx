#pragma once

#include "kovhalan/adapters/InputHandler.hxx"
#include "kovhalan/adapters/PlayerMoveCommand.hxx"
#include "kovhalan/drivers/Renderer.hxx"
#include "kovhalan/use_cases/MovePlayerUseCase.hxx"

namespace kovhalan {
namespace adapters {
class PlayerController {
 public:
    PlayerController( std::shared_ptr<use_cases::MovePlayerUseCase> aPlayerMoveUseCase, std::shared_ptr<drivers::Renderer> renderer);

 public:
    InputHandler::KeyMap createKeyBinds();

    void                 draw();

 private:
    std::shared_ptr<use_cases::MovePlayerUseCase> move_use_case_;
    std::shared_ptr<drivers::Renderer>            renderer_;
};
} // namespace adapters
} // namespace kovhalan