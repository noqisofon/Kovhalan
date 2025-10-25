#pragma once

#include "kovhalan/domain/Entity.hxx"

namespace kovhalan {
namespace domain {
/*!
 * \brief アクター（キャラクター）を表すエンティティの基底クラス
 */
class Actor : public Entity {
 public:
    virtual bool canMove( std::int32_t dx, std::int32_t dy ) const = 0;

    virtual void moveTo( std::int32_t dx, std::int32_t dy )        = 0;

    virtual void setPosition( std::int32_t x, std::int32_t y )     = 0;
};
} // namespace domain
} // namespace kovhalan
