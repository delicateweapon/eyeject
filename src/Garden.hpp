#pragma once

#include "Object2D.hpp"
#include <cstdint>
#include <vector>

class Garden : public Object2D_Translate {
public:
    static std::vector<Garden *> gardens;
    static void add(Garden& g);

    uint16_t tile_size;
    
    Garden(float x, float y, uint16_t width, uint16_t height, uint16_t tile_size);

    void render();
    void surround_with_walls();
    bool check_occupancy(float x, float y);

private:
    uint16_t row_count;
    uint16_t col_count;
    uint16_t tile_count;
    std::vector<bool> occupied;
};
