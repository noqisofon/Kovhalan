#pragma once

#include <cstdint>
#include <cassert>
#include <map>
#include <memory>
#include <string>


#include <spdlog/spdlog.h>

/* vcpkg でインストールした sdl2 には SDL2main.lib が入っていないので、SDL_MAIN_HANDLED を定義しておく。 */
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

//#include <SDL2pp/SDL2pp.hh>