#include "kovhalan/drivers/Texture.hxx"

namespace kovhalan {
namespace drivers {
Texture::Texture() : texture_{ nullptr } {}
Texture::Texture( SDL_Texture *nativeTexture ) : texture_{ nativeTexture } {}
} // namespace drivers
} // namespace kovhalan
