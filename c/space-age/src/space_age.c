#include "space_age.h"

#define EARTH 31557600

const double orbits[] =
    { EARTH * 0.2408467     // Mercury
    , EARTH * 0.61519726    // Venus
    , EARTH                 // Earth
    , EARTH * 1.8808158     // Mars
    , EARTH * 11.862615     // Jupiter
    , EARTH * 29.447498     // Saturn
    , EARTH * 84.016846     // Uranus
    , EARTH * 164.79132     // Neptune
    };

float convert_planet_age(planet_t planet, int64_t input) {
    return input / orbits[planet];
}
