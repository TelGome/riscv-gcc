/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** abs\ta[0-9],a[0-9]
** ...
*/

uint64_t f0 (int64_t x0){
    return __rv_abs(x0);
}

