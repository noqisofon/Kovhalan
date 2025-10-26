#pragma once

#include "kovhalan/domain/Entity.hxx"

namespace kovhalan {
namespace domain {
/*!
 * \brief ダンジョンの床に落ちているアイテムを表すエンティティ
 */
class DroppedItem : public Entity {
 public:
    DroppedItem();
    virtual ~DroppedItem();

 public:
    std::int32_t          id() const override;

    std::shared_ptr<Item> item() const;
};
} // namespace domain
} // namespace kovhalan
