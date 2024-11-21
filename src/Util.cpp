#include "App.hpp"
#include "constants.hpp"

#include <cmath>

using namespace App;

static float two_pi = Constants::PI * 2;

void Util::angle_abs(float &angle)
{
    if (angle < 0) {
        angle -= two_pi * std::floor(angle / two_pi);
    } else if (angle > 2 * Constants::PI) {
        angle -= two_pi * std::floor(angle / two_pi);
    }
}
