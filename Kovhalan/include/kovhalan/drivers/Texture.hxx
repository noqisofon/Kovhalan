#pragma once

#include "kovhalan/kovhalan.hxx"

namespace kovhalan {
namespace drivers {
class Texture {
 public:
    Texture();
    Texture( SDL_Texture *nativeTexture );

 public:
    SDL_Texture *nativeTexture() const { return texture_; }

 private:
    SDL_Texture *texture_;
};
} // namespace drivers
} // namespace kovhalan
