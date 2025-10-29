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

        std::int32_t room_x      = Distribution{ 1, static_cast<std::int32_t>( width ) - room_width - 1 }( rng_ );
        std::int32_t room_y      = Distribution{ 1, static_cast<std::int32_t>( height ) - room_height - 1 }( rng_ );

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

        // Dig out the room
        for ( std::int32_t room_y = new_room.y(); room_y < new_room.y() + new_room.height(); ++room_y ) {
            for ( std::int32_t room_x = new_room.x(); room_x < new_room.x() + new_room.width(); ++room_x ) {
                dungeon_floor->positionPutTileType( room_x, room_y, domain::TileType::Floor );
            }
        }

        if ( !rooms.empty() ) {
            Distribution coin_tos{ 0, 1 };

            std::int32_t prev_x = rooms.back().x() + rooms.back().width() / 2;
            std::int32_t prev_y = rooms.back().y() + rooms.back().height() / 2;
            std::int32_t new_x  = new_room.x() + new_room.width() / 2;
            std::int32_t new_y  = new_room.y() + new_room.height() / 2;

            if ( coin_tos( rng_ ) == 0 ) {
                // Horizontal then vertical
                for ( std::int32_t cx = std::min( prev_x, new_x ); cx <= std::max( prev_x, new_x ); ++cx ) {
                    dungeon_floor->positionPutTileType( cx, prev_y, domain::TileType::Floor );
                }
                for ( std::int32_t cy = std::min( prev_y, new_y ); cy <= std::max( prev_y, new_y ); ++cy ) {
                    dungeon_floor->positionPutTileType( new_x, cy, domain::TileType::Floor );
                }
            } else {
                // Vertical then horizontal
                for ( std::int32_t cy = std::min( prev_y, new_y ); cy <= std::max( prev_y, new_y ); ++cy ) {
                    dungeon_floor->positionPutTileType( prev_x, cy, domain::TileType::Floor );
                }
                for ( std::int32_t cx = std::min( prev_x, new_x ); cx <= std::max( prev_x, new_x ); ++cx ) {
                    dungeon_floor->positionPutTileType( cx, new_y, domain::TileType::Floor );
                }
            }
        }

        rooms.push_back( new_room );
    }

    return dungeon_floor;
}
} // namespace use_cases
} // namespace kovhalan
