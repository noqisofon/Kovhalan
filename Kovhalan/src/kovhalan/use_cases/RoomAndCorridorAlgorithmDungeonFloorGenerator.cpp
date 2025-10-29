#include "kovhalan/domain/Room.hxx"

#include "kovhalan/use_cases/RoomAndCorridorAlgorithmDungeonFloorGenerator.hxx"

namespace kovhalan {
namespace use_cases {

RoomAndCorridorAlgorithmDungeonFloorGenerator::RoomAndCorridorAlgorithmDungeonFloorGenerator( std::int32_t maxRooms,
                                                                                              std::int32_t minRoomSize,
                                                                                              std::int32_t maxRoomSize )
    : rng_{ std::random_device{}() }, max_rooms_{ maxRooms }, min_room_size_{ minRoomSize },
      max_room_size_{ maxRoomSize } {}

std::shared_ptr<domain::DungeonFloor> RoomAndCorridorAlgorithmDungeonFloorGenerator::generate( std::uint32_t width,
                                                                                               std::uint32_t height ) {
    using Distribution = std::uniform_int_distribution<std::int32_t>;

    auto dungeon_floor = std::make_shared<domain::DungeonFloor>( width, height );

    for ( std::uint32_t y = 0; y < height; ++y ) {
        for ( std::uint32_t x = 0; x < width; ++x ) {
            dungeon_floor->positionPutTileType( x, y, domain::TileType::Wall );
        }
    }

    Distribution              width_distri{ min_room_size_, max_room_size_ };
    Distribution              height_distri{ min_room_size_, max_room_size_ };

    std::vector<domain::Room> rooms;
    for ( std::int32_t room_index = 0; room_index < max_rooms_; ++room_index ) {
        std::int32_t room_width  = width_distri( rng_ );
        std::int32_t room_height = width_distri( rng_ );

        std::int32_t room_x      = Distribution{ 1, width - room_width - 1 }( rng_ );
        std::int32_t room_y      = Distribution{ 1, height - room_height - 1 }( rng_ );

        domain::Room new_room{ room_x, room_y, room_width, room_height };
        bool         intersects{ false };
        for ( const auto &other_room : rooms ) {
            if ( room_x < other_room.x() + other_room.width() && room_x + room_width > other_room.x() &&
                 room_y < other_room.y() + other_room.height() && room_y + room_height > other_room.y() ) {
                intersects = true;
                break;
            }
        }

        if ( intersects ) {
            continue;
        }
    }
}

} // namespace use_cases
} // namespace kovhalan
