/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pslli.b\ta[0-9],a[0-9],1
** ...
*/
uint8x8_t f0 (uint8x8_t x0, uint32_t x1){
    return __riscv_psll_s_u8x8(x0, 1);
}

/*
**f1:
** psll.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint8x8_t f1 (uint8x8_t x0, uint32_t x1){
    return __riscv_psll_s_u8x8(x0, x1);
}

