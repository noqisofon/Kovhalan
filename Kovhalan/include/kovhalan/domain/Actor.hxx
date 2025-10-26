#pragma once

#include "kovhalan/domain/Entity.hxx"
#include "kovhalan/domain/IMapValidator.hxx"

namespace kovhalan {
namespace domain {
/*!
 * \brief アクター（キャラクター）を表すエンティティの基底クラス
 */
class Actor : public Entity {
 public:
    using Position = std::tuple<std::int32_t, std::int32_t>;

 public:
    virtual Position getPosition() const                                                                         = 0;

    virtual bool canMove( std::int32_t dx, std::int32_t dy, std::shared_ptr<IMapValidator> &mapValidator ) const = 0;

    virtual void moveTo( std::int32_t dx, std::int32_t dy )                                                      = 0;

    virtual void setPosition( std::int32_t x, std::int32_t y )                                                   = 0;
};
} // namespace domain
} // namespace kovhalan
