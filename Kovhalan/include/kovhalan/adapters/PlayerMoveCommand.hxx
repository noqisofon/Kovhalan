#pragma once

#include "kovhalan/adapters/ICommand.hxx"
#include "kovhalan/adapters/MovePlayerUseCase.hxx"

namespace kovhalan {
namespace adapters {
class PlayerMoveCommand : public ICommand {
 public:
    PlayerMoveCommand( std::shared_ptr<MovePlayerUseCase> aMovePlayerUseCase, std::int32_t dx, std::int32_t dy );

 public:
    void execute() override;

 private:
    std::shared_ptr<MovePlayerUseCase> use_case_;
    std::int32_t                       dx_;
    std::int32_t                       dy_;
};
} // namespace adapters
} // namespace kovhalan
