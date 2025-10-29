#pragma once

#include "kovhalan/kovhalan.hxx"

namespace kovhalan {
namespace domain {
/*!
 * \brief 部屋を表すクラスを定義します。
 */
class Room {
 public:
    Room( std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height )
        : x_{ x }, y_{ y }, width_{ width }, height_{ height } {}

 public:
    std::int32_t x() const { return x_; }
    std::int32_t y() const { return y_; }
    std::int32_t width() const { return width_; }
    std::int32_t height() const { return height_; }

 private:
    std::int32_t x_;
    std::int32_t y_;
    std::int32_t width_;
    std::int32_t height_;
};
} // namespace domain
} // namespace kovhalan
