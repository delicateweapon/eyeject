#pragma once

#include <cstdint>

namespace Garden {

namespace Area {
  constexpr uint16_t width = 30;
  constexpr uint16_t height = 20;
  constexpr uint16_t tile_size = 15;
  extern bool occupied[width][height];
}

void area_init();
void area_render();
  
}
