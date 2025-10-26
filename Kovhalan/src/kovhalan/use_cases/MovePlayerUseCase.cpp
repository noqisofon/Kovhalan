#include "kovhalan/use_cases/MovePlayerUseCase.hxx"

namespace kovhalan {
namespace use_cases {
MovePlayerUseCase::MovePlayerUseCase( std::shared_ptr<use_cases::IPlayerRepository> playerRepository,
                                      std::shared_ptr<domain::IMapValidator>        mapValidator )
    : player_repository_( std::move( playerRepository ) ), map_validator_{ std::move( mapValidator ) } {}

bool MovePlayerUseCase::execute( std::uint32_t dx, std::uint32_t dy ) {
    auto player = player_repository_->getPlayer();
    if ( !player ) {
        // プレイヤーが見つからなかった場合は終了。
        return false;
    }

    auto         player_position = player->getPosition();
    std::int32_t new_x           = std::get<0>( player_position ) + dx;
    std::int32_t new_y           = std::get<1>( player_position ) + dy;

    if ( !player->canMove( new_x, new_y, map_validator_ ) ) {
        // 指定された地点に移動できなかった場合は終了。
        return false;
    }

    // プレイヤーを移動。
    player->moveTo( new_x, new_y );

    // プレイヤーのデータを更新します。
    player_repository_->savePlayer( *player );

    return true;
}
} // namespace use_cases
} // namespace kovhalan
