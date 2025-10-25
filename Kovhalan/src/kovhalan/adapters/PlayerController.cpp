#include "kovhalan/adapters/PlayerController.hxx"

namespace kovhalan {
namespace adapters {
PlayerController::PlayerController( std::shared_ptr<use_cases::MovePlayerUseCase> aPlayerMoveUseCase,
                                    std::shared_ptr<drivers::Renderer>            renderer )
    : move_use_case_{ aPlayerMoveUseCase }, renderer_{ renderer } {}

InputHandler::KeyMap PlayerController::createKeyBinds() {
    return InputHandler::KeyMap{
        {SDL_SCANCODE_W, std::make_shared<PlayerMoveCommand>( move_use_case_,  0, -1 )},
        {SDL_SCANCODE_S, std::make_shared<PlayerMoveCommand>( move_use_case_,  0,  1 )},
        {SDL_SCANCODE_A, std::make_shared<PlayerMoveCommand>( move_use_case_, -1,  0 )},
        {SDL_SCANCODE_D, std::make_shared<PlayerMoveCommand>( move_use_case_,  1,  0 )},
    };
}

void PlayerController::draw() {
    // TODO
    //spdlog::info( "PlayerController::draw() called" );
}
} // namespace adapters
} // namespace kovhalan