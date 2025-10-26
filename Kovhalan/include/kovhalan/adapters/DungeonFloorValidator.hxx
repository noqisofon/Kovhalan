#pragma once

#include "kovhalan/use_cases/IMapValidator.hxx"
#include "kovhalan/domain/DungeonFloor.hxx"

namespace kovhalan {
namespace adapters {
/*!
 * \brief ダンジョンフロアのマップ検証を行うためのクラスを定義します。
 */
class DungeonFloorValidator : public use_cases::IMapValidator {
 public:
    DungeonFloorValidator( std::shared_ptr<domain::DungeonFloor> dungeonFloor );

 public:
    /*!
     * \brief 指定された座標が通行可能かどうかを検証します。
     *
     * \param x x 座標上の位置。
     * \param y y 座標上の位置。
     *
     * \return 通行可能なら `true`。それ以外なら `false`。
     */
    bool isTileWalkable( std::int32_t x, std::int32_t y ) const override;

 private:
    std::shared_ptr<domain::DungeonFloor> dungeon_floor_;
};
} // namespace adapters
} // namespace kovhalan
