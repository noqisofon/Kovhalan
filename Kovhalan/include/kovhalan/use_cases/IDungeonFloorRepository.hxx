#pragma once

#include "kovhalan/kovhalan.hxx"
#include "kovhalan/domain/DungeonFloor.hxx"

namespace kovhalan {
namespace use_cases {
/*!
 * \brief ダンジョンフロアのリポジトリインターフェースを定義します。
 */
class IDungeonFloorRepository {
 public:
    virtual ~IDungeonFloorRepository() = default;

 public:
    virtual std::shared_ptr<domain::DungeonFloor> currentDungeon() const                 = 0;

    virtual void saveDungeonFloor( std::shared_ptr<domain::DungeonFloor> aDungeonFloor ) = 0;
};
} // namespace use_cases
} // namespace kovhalan
