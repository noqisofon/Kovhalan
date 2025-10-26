#pragma once

#include "kovhalan/kovhalan.hxx"

namespace kovhalan {
namespace domain {
/*!
 * \brief ダンジョンのタイルの種類。
 */
enum class TileType {
    Unknown,    //!< 不明(初期値)
    Wall,       //!< 壁
    Floor,      //!< 床
    CloseDoor,  //!< 閉じたドア
    OpenDoor,   //!< 開いたドア
    BrokenDoor, //!< 壊れたドア
    StairDown,  //!< 下へ向かう階段
    Stairup,    //!< 上へ向かう階段
};

/*!
 * \brief ダンジョンフロアを表すクラスを定義します。
 */
class DungeonFloor {
 public:
    DungeonFloor( std::uint32_t width, std::uint32_t height );

 public:
    TileType positionAtTileType( std::int32_t x, std::int32_t y ) const;
    void     positionPutTileType( std::int32_t x, std::int32_t y, TileType tileType );
    bool     isTileWalkable( std::int32_t x, std::int32_t y ) const;

 private:
    std::uint32_t                   width_;
    std::uint32_t                   height_;

    boost::multi_array<TileType, 2> tiles_;
};
} // namespace domain
} // namespace kovhalan
