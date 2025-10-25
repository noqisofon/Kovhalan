#pragma once

#include "kovhalan/adapters/ICommand.hxx"
#include "kovhalan/use_cases/MovePlayerUseCase.hxx"

namespace kovhalan {
namespace adapters {
class PlayerMoveCommand : public ICommand {
 public:
    PlayerMoveCommand( std::shared_ptr<use_cases::MovePlayerUseCase> aMovePlayerUseCase,
                       std::int32_t                                  dx,
                       std::int32_t                                  dy );

 public:
    void execute() override;

 private:
    std::shared_ptr<use_cases::MovePlayerUseCase> use_case_;
    std::int32_t                                  dx_;
    std::int32_t                                  dy_;
};
} // namespace adapters
} // namespace kovhalan
