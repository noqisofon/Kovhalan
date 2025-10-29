#pragma once

#include "kovhalan/use_cases/IDungeonFloorGenerator.hxx"

namespace kovhalan {
namespace use_cases {

/*!
 * \brief 部屋と通路のアルゴリズムを使用してダンジョンフロアを生成するクラス
 */
class RoomAndCorridorAlgorithmDungeonFloorGenerator : public IDungeonFloorGenerator {
 public:
    RoomAndCorridorAlgorithmDungeonFloorGenerator( std::int32_t maxRooms    = 30,
                                                   std::int32_t minRoomSize = 6,
                                                   std::int32_t maxRoomSize = 10 );
    virtual ~RoomAndCorridorAlgorithmDungeonFloorGenerator() = default;

 public:
    /*!
     * \brief ダンジョンフロアを生成し、返します。
     * \param width ダンジョンフロアの幅
     * \param height ダンジョンフロアの高さ
     * \return 生成されたダンジョンフロア。
     */
    std::shared_ptr<domain::DungeonFloor> generate( std::uint32_t width, std::uint32_t height ) override;

 private:
    std::mt19937 rng_;

    std::int32_t max_rooms_     = 30; //!< ダンジョンフロア内における最大部屋数。
    std::int32_t min_room_size_ = 6;  //!< 部屋の最小サイズ(単位はマス目)。
    std::int32_t max_room_size_ = 10; //!< 部屋の最大サイズ(単位はマス目)。
};
} // namespace use_cases
} // namespace kovhalan
