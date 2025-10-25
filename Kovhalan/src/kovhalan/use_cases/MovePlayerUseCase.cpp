#include "kovhalan/use_cases/MovePlayerUseCase.hxx"

namespace kovhalan {
namespace use_cases {
MovePlayerUseCase::MovePlayerUseCase( std::shared_ptr<repositories::IPlayerRepository> player_repository )
    : player_repository_( std::move( player_repository ) ) {}

bool MovePlayerUseCase::execute( std::uint32_t x, std::uint32_t y ) {
    auto player = player_repository_->getPlayer();
    if ( !player ) {
        // プレイヤーが見つからなかった場合は終了。
        return false;
    }
    if ( !player->canMove( x, y ) ) {
        // 指定された地点に移動できなかった場合は終了。
        return false;
    }

    // プレイヤーを移動。
    player->moveTo( x, y );

    // プレイヤーのデータを更新します。
    player_repository_->savePlayer( *player );

    return true;
}
} // namespace use_cases
} // namespace kovhalan
