#include "kovhalan/domain/DungeonFloor.hxx"

#include "kovhalan/use_cases/GenerateDungeonUseCase.hxx"

namespace kovhalan {
namespace use_cases {
GenerateDungeonUseCase::GenerateDungeonUseCase( std::shared_ptr<IDungeonFloorRepository> aDungeonFloorRepository )
    : dungeon_floor_repository_{ aDungeonFloorRepository }, rng_{ std::random_device{}() } {}

void GenerateDungeonUseCase::execute( std::uint32_t width, std::uint32_t height ) {
    using Distribution         = std::uniform_int_distribution<std::int32_t>;

    auto         dungeon_floor = std::make_shared<domain::DungeonFloor>( width, height );

    /* なんらかの生成アルゴリズムを呼び出す。 */
    // callAutomataAlgorithm(dungeon_floor);

    Distribution width_distri{ 5, 10 };
    Distribution height_distri{ 5, 8 };
    Distribution x_axis_distri{ 1, static_cast<std::int32_t>( width ) - 11 };
    Distribution y_axis_distri{ 1, static_cast<std::int32_t>( height ) - 9 };

    /* とりあえず、大きな部屋を作る。 */
    std::int32_t room_width  = width_distri( rng_ );
    std::int32_t room_height = height_distri( rng_ );
    std::int32_t start_x     = x_axis_distri( rng_ );
    std::int32_t start_y     = y_axis_distri( rng_ );

    for ( std::int32_t y = start_y; y < start_y + room_height; ++y ) {
        for ( std::int32_t x = start_x; x < start_y + room_width; ++x ) {
            dungeon_floor->positionPutTileType( x, y, domain::TileType::Floor );
        }
    }

    dungeon_floor_repository_->saveDungeonFloor( dungeon_floor );
}
} // namespace use_cases
} // namespace kovhalan
