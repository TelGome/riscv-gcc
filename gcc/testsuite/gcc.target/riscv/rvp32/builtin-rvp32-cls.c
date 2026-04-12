/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** cls\ta[0-9],a[0-9]
** ...
*/

uint32_t f0 (int32_t x0){
    return __rv_cls(x0);
}

