/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** absw\ta[0-9],a[0-9]
** ...
*/

uint64_t f0 (int32_t x0){
    return __rv_absw(x0);
}

