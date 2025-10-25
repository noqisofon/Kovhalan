#include "kovhalan/adapters/PlayerMoveCommand.hxx"

namespace kovhalan {
namespace adapters {
PlayerMoveCommand::PlayerMoveCommand( std::shared_ptr<use_cases::MovePlayerUseCase> aMovePlayerUseCase,
                                      std::int32_t                                  dx,
                                      std::int32_t                                  dy )
    : use_case_{ aMovePlayerUseCase }, dx_{ dx }, dy_{ dy } {}

void PlayerMoveCommand::execute() {
    // Implementation of player movement using use_case_, dx_, and dy_
}
} // namespace adapters
} // namespace kovhalan
