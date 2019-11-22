#define SBOX_NEXT K13
#include "literals/sbox.h"
#define T0_NEXT (SBOX ^ ROUND_CONSTANT)
#include "literals/T0.h"
#define SBOX_NEXT K14
#include "literals/sbox.h"
#define T1_NEXT SBOX
#include "literals/T1.h"
#define SBOX_NEXT K15
#include "literals/sbox.h"
#define T2_NEXT SBOX
#include "literals/T2.h"
#define SBOX_NEXT K12
#include "literals/sbox.h"
#define T3_NEXT SBOX
#include "literals/T3.h"

#define K0_NEXT (K0 ^ T0)
#define K1_NEXT (K1 ^ T1)
#define K2_NEXT (K2 ^ T2)
#define K3_NEXT (K3 ^ T3)
#define K4_NEXT (K0_NEXT ^ K4)
#define K5_NEXT (K1_NEXT ^ K5)
#define K6_NEXT (K2_NEXT ^ K6)
#define K7_NEXT (K3_NEXT ^ K7)
#define K8_NEXT (K4_NEXT ^ K8)
#define K9_NEXT (K5_NEXT ^ K9)
#define K10_NEXT (K6_NEXT ^ K10)
#define K11_NEXT (K7_NEXT ^ K11)
#define K12_NEXT (K8_NEXT ^ K12)
#define K13_NEXT (K9_NEXT ^ K13)
#define K14_NEXT (K10_NEXT ^ K14)
#define K15_NEXT (K11_NEXT ^ K15)
#include "transform_key.h"
