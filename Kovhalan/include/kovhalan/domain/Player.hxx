#pragma once

#include "kovhalan/domain/Actor.hxx"

namespace kovhalan {
namespace domain {
/*!
 * \brief プレイヤーを表すエンティティのクラス
 */
class Player : public Actor {
 public:
    Player( const Player &other );

 public:
    std::int32_t    id() const override;

    Actor::Position getPosition() const override;

    bool canMove( std::int32_t dx, std::int32_t dy, std::shared_ptr<IMapValidator> &mapValidator ) const override;

    void moveTo( std::int32_t dx, std::int32_t dy ) override;

    void setPosition( std::int32_t x, std::int32_t y ) override;

 private:
    std::int32_t x_;
    std::int32_t y_;
};
} // namespace domain
} // namespace kovhalan
