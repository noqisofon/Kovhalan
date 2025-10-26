#pragma once

#include "kovhalan/repositories/IDungeonFloorRepository.hxx"

namespace kovhalan {
namespace use_cases {
class GenerateDungeonUseCase {
 public:
    GenerateDungeonUseCase( std::shared_ptr<repositories::IDungeonFloorRepository> aDungeonFloorRepository );

public:
    void execute(std::uint32_t width, std::uint32_t height);

 private:
    std::shared_ptr<repositories::IDungeonFloorRepository> dungeon_floor_repository_;
    std::mt19937                                           rng_;
};
} // namespace use_cases
} // namespace kovhalan
