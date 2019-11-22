#define X(x) ((((x) << 1) ^ ((((x) >> 7) & 1) * 27)) & 255)
#define C0T0 B0
#define C0T1 (B0 ^ B1 ^ B2 ^ B3)
#define B0_NEXT (B0 ^ X(B0 ^ B1) ^ C0T1)
#define B1_NEXT (B1 ^ X(B1 ^ B2) ^ C0T1)
#define B2_NEXT (B2 ^ X(B2 ^ B3) ^ C0T1)
#define B3_NEXT (B3 ^ X(B3 ^ C0T0) ^ C0T1)
#define C1T0 B4
#define C1T1 (B4 ^ B5 ^ B6 ^ B7)
#define B4_NEXT (B4 ^ X(B4 ^ B5) ^ C1T1)
#define B5_NEXT (B5 ^ X(B5 ^ B6) ^ C1T1)
#define B6_NEXT (B6 ^ X(B6 ^ B7) ^ C1T1)
#define B7_NEXT (B7 ^ X(B7 ^ C1T0) ^ C1T1)
#define C2T0 B8
#define C2T1 (B8 ^ B9 ^ B10 ^ B11)
#define B8_NEXT (B8 ^ X(B8 ^ B9) ^ C2T1)
#define B9_NEXT (B9 ^ X(B9 ^ B10) ^ C2T1)
#define B10_NEXT (B10 ^ X(B10 ^ B11) ^ C2T1)
#define B11_NEXT (B11 ^ X(B11 ^ C2T0) ^ C2T1)
#define C3T0 B12
#define C3T1 (B12 ^ B13 ^ B14 ^ B15)
#define B12_NEXT (B12 ^ X(B12 ^ B13) ^ C3T1)
#define B13_NEXT (B13 ^ X(B13 ^ B14) ^ C3T1)
#define B14_NEXT (B14 ^ X(B14 ^ B15) ^ C3T1)
#define B15_NEXT (B15 ^ X(B15 ^ C3T0) ^ C3T1)
#include "transform_block.h"
#undef X
#undef C0T0
#undef C0T1
#undef C1T0
#undef C1T1
#undef C2T0
#undef C2T1
#undef C3T0
#undef C3T1
