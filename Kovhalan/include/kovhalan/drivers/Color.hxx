#pragma once

#include "kovhalan/kovhalan.hxx"

namespace kovhalan {
namespace drivers {

class Color {
 public:
    Color() : Color{ 0, 0, 0, 255 } {}
    Color( std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255 )
        : red_{ red }, green_{ green }, blue_{ blue }, alpha_{ alpha } {}
    Color( SDL_Color &nativeColor ) : Color{ nativeColor.r, nativeColor.g, nativeColor.b, nativeColor.a } {}

    ~Color() = default;

 public:
    std::uint8_t red() const { return red_; }
    std::uint8_t green() const { return green_; }
    std::uint8_t blue() const { return blue_; }
    std::uint8_t alpha() const { return alpha_; }

 private:
    std::uint8_t red_;
    std::uint8_t green_;
    std::uint8_t blue_;
    std::uint8_t alpha_;
};

} // namespace drivers
} // namespace kovhalan
