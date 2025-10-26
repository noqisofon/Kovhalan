#include "kovhalan/adapters/DungeonFloorValidator.hxx"

namespace kovhalan {
namespace adapters {
DungeonFloorValidator::DungeonFloorValidator( std::shared_ptr<domain::DungeonFloor> dungeonFloor )
    : dungeon_floor_{ dungeonFloor } {}

bool DungeonFloorValidator::isTileWalkable( std::int32_t x, std::int32_t y ) const {
    return dungeon_floor_->isTileWalkable( x, y );
}
} // namespace adapters
} // namespace kovhalan
