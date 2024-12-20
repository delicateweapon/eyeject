#pragma once

#include <cstdint>

class Color {
public:
    uint8_t r, g, b;

    Color() = default;
    Color(uint8_t r, uint8_t g, uint8_t b);
    Color(uint32_t hex);
};
