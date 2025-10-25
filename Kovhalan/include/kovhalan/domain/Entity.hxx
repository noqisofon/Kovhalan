#pragma once

#include "kovhalan/kovhalan.hxx"

namespace kovhalan {
namespace domain {
/*!
 * \brief ドメインエンティティの基底クラス
 */
class Entity {
 protected:
    Entity() = default;

 public:
    virtual ~Entity() = default;

 public:
    virtual std::int32_t id() const = 0;
};
} // namespace domain
} // namespace kovhalan
