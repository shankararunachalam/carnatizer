#include "types.h"

// carnatic swarasthana ratios

const typedef struct ratio {
  const char *name;
  const u8 interval_number;
  const u8 numerator;
  const u8 denominator;
} ratio;

const ratio swarasthanas[17] = {
    { "S",  0,   1,  1 },
    { "R1", 1,  16, 15 },
    { "R2", 2,   9,  8 },
    { "R3", 3,   6,  5 },
    { "G1", 2,   9,  8 },
    { "G2", 3,   6,  5 },
    { "G3", 4,   5,  4 },
    { "M1", 5,   4,  3 },
    { "M2", 6,  45, 32 },
    { "P",  7,   3,  2 },
    { "D1", 8,   8,  5 },
    { "D2", 9,  27, 16 },
    { "D3", 10,  9,  5 },
    { "N1", 9,  27, 16 },
    { "N2", 10,  9,  5 },
    { "N3", 11, 15,  8 },
    { "S.", 12,  2,  1 }
};