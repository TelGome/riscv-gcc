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

/*
**f2:
** pslli.b\ta[0-9],a[0-9],1
** ...
*/
int8x8_t f2 (int8x8_t x0, uint32_t x1){
    return __riscv_psll_s_i8x8(x0, 1);
}

/*
**f3:
** psll.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/
int8x8_t f3 (int8x8_t x0, uint32_t x1){
    return __riscv_psll_s_i8x8(x0, x1);
}

/*
**f4:
** pslli.h\ta[0-9],a[0-9],1
** ...
*/
uint16x4_t f4 (uint16x4_t x0, uint32_t x1){
    return __riscv_psll_s_u16x4(x0, 1);
}

/*
**f5:
** psll.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint16x4_t f5 (uint16x4_t x0, uint32_t x1){
    return __riscv_psll_s_u16x4(x0, x1);
}

/*
**f6:
** pslli.h\ta[0-9],a[0-9],1
** ...
*/
int16x4_t f6 (int16x4_t x0, uint32_t x1){
    return __riscv_psll_s_i16x4(x0, 1);
}

/*
**f7:
** psll.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/
int16x4_t f7 (int16x4_t x0, uint32_t x1){
    return __riscv_psll_s_i16x4(x0, x1);
}

/*
**f8:
** pslli.w\ta[0-9],a[0-9],1
** ...
*/
uint32x2_t f8 (uint32x2_t x0, uint32_t x1){
    return __riscv_psll_s_u32x2(x0, 1);
}

/*
**f9:
** psll.ws\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint32x2_t f9 (uint32x2_t x0, uint32_t x1){
    return __riscv_psll_s_u32x2(x0, x1);
}

/*
**f10:
** pslli.w\ta[0-9],a[0-9],1
** ...
*/
int32x2_t f10 (int32x2_t x0, uint32_t x1){
    return __riscv_psll_s_i32x2(x0, 1);
}

/*
**f11:
** psll.ws\ta[0-9],a[0-9],a[0-9]
** ...
*/
int32x2_t f11 (int32x2_t x0, uint32_t x1){
    return __riscv_psll_s_i32x2(x0, x1);
}

