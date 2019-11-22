#ifndef N
#   error "please define N before including fib.h"
#endif
#
#ifndef __I
#   define __I 0
#   define __F0 0
#   define __F1 1
#else
#   define __I_NEXT (__I + 1)
#   include "literal___I.h"
#
#   define __TMP_NEXT (__F0 + __F1)
#   include "literal___TMP.h"
#
#   define __F0_NEXT __F1
#   include "literal___F0.h"
#   define __F1_NEXT __TMP
#   include "literal___F1.h"
#   undef __TMP
#endif
#
#if __I == N
#   define R_NEXT __F0
#   include "literal_R.h"
#   undef __I
#   undef __F0
#   undef __F1
#else
#   include __FILE__
#endif
