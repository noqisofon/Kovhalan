#pragma once

#include "kovhalan/kovhalan.hxx"

namespace kovhalan {
namespace domain {
/*!
 * \brief マップの検証を行うためのインターフェースを定義します。
 */
class IMapValidator {
 public:
    virtual ~IMapValidator() = default;

 public:
    /*!
     * \brief 指定された座標が通行可能かどうかを検証します。
     *
     * \param x x 座標上の位置。
     * \param y y 座標上の位置。
     *
     * \return 通行可能なら `true`。それ以外なら `false`。
     */
    virtual bool isTileWalkable( std::int32_t x, std::int32_t y ) const = 0;
};
} // namespace domain
} // namespace kovhalan
