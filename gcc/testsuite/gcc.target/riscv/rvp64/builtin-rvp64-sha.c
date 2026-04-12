/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** sha\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int x1){
    return __rv_sha(x0, x1);
}

