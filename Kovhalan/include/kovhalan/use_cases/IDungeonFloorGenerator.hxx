#pragma once

#include "kovhalan/domain/DungeonFloor.hxx"

namespace kovhalan {
namespace use_cases {
/*!
 * \brief ダンジョンフロアを生成するインターフェース
 */
class IDungeonFloorGenerator {
 public:
    virtual ~IDungeonFloorGenerator() = default;

 public:
    /*!
     * \brief ダンジョンフロアを生成し、返します。
     * \param width ダンジョンフロアの幅
     * \param height ダンジョンフロアの高さ
     * \return 生成されたダンジョンフロア。
     */
    virtual std::shared_ptr<domain::DungeonFloor> generate( std::uint32_t width, std::uint32_t height ) = 0;
};
} // namespace use_cases
} // namespace kovhalan
