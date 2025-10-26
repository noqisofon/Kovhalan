#include "kovhalan/domain/Player.hxx"

namespace kovhalan {
namespace domain {
Player::Player( const Player &other ) : x_{ other.x_ }, y_{ other.y_ } {}

std::int32_t    Player::id() const { return 0; }

Actor::Position Player::getPosition() const { return { x_, y_ }; }

bool Player::canMove( std::int32_t dx, std::int32_t dy, std::shared_ptr<domain::IMapValidator> &mapValidator ) const {
    return mapValidator->isTileWalkable( x_ + dx, y_ + dy );
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
