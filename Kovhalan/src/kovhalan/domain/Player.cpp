#include "kovhalan/domain/Player.hxx"

namespace kovhalan {
namespace domain {
Player::Player( const Player &other ) : x_{ other.x_ }, y_{ other.y_ } {}

std::int32_t Player::id() const { return 0; }

bool         Player::canMove( std::int32_t dx, std::int32_t dy ) const {
    /* TODO: 現在いるダンジョンフロアを参照する方法が不明。 */
    return false;
}

void Player::moveTo( std::int32_t dx, std::int32_t dy ) {
    /* TODO: こっちも。 */
    x_ += dx;
    y_ += dy;
}

void Player::setPosition( std::int32_t x, std::int32_t y ) {
    x_ = x;
    y_ = y;
}
} // namespace domain
} // namespace kovhalan
