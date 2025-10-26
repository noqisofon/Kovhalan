#include "kovhalan/domain/DungeonFloor.hxx"

namespace kovhalan {
namespace domain {
DungeonFloor::DungeonFloor( std::uint32_t width, std::uint32_t height )
    : width_{ width }, height_{ height }, tiles_{ boost::extents[height][width] } {}

TileType DungeonFloor::positionAtTileType( std::int32_t x, std::int32_t y ) const { return tiles_[y][x]; }

void DungeonFloor::positionPutTileType( std::int32_t x, std::int32_t y, TileType tileType ) { tiles_[y][x] = tileType; }

bool DungeonFloor::isTileWalkable( std::int32_t x, std::int32_t y ) const {
    return tiles_[y][x] == TileType::Floor || tiles_[y][x] == TileType::OpenDoor ||
           tiles_[y][x] == TileType::BrokenDoor;
}
} // namespace domain
} // namespace kovhalan
