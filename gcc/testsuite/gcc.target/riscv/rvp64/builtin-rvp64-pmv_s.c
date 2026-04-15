/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** padd.bs\ta[0-9],x0,a[0-9]
** ...
*/
uint8x8_t f0 (uint8_t x0){
    return __riscv_pmv_s_u8x8(x0);
}

/*
**f1:
** pli.b\ta[0-9],1
** ...
*/
uint8x8_t f1 (uint8_t x0){
    return __riscv_pmv_s_u8x8(1);
}

/*
**f2:
** padd.bs\ta[0-9],x0,a[0-9]
** ...
*/
int8x8_t f2 (int8_t x0){
    return __riscv_pmv_s_i8x8(x0);
}

/*
**f3:
** pli.b\ta[0-9],1
** ...
*/
int8x8_t f3 (int8_t x0){
    return __riscv_pmv_s_i8x8(1);
}

/*
**f4:
** padd.hs\ta[0-9],x0,a[0-9]
** ...
*/
uint16x4_t f4 (uint16_t x0){
    return __riscv_pmv_s_u16x4(x0);
}

/*
**f5:
** pli.h\ta[0-9],1
** ...
*/
uint16x4_t f5 (uint16_t x0){
    return __riscv_pmv_s_u16x4(1);
}

/*
**f6:
** plui.h\ta[0-9],1024
** ...
*/
uint16x4_t f6 (uint16_t x0){
    return __riscv_pmv_s_u16x4(1024);
}

/*
**f7:
** padd.hs\ta[0-9],x0,a[0-9]
** ...
*/
int16x4_t f7 (int16_t x0){
    return __riscv_pmv_s_i16x4(x0);
}

/*
**f8:
** pli.h\ta[0-9],1
** ...
*/
int16x4_t f8 (int16_t x0){
    return __riscv_pmv_s_i16x4(1);
}

/*
**f9:
** plui.h\ta[0-9],1024
** ...
*/
int16x4_t f9 (int16_t x0){
    return __riscv_pmv_s_i16x4(1024);
}

/*
**f10:
** padd.ws\ta[0-9],x0,a[0-9]
** ...
*/
uint32x2_t f10 (uint32_t x0){
    return __riscv_pmv_s_u32x2(x0);
}

/*
**f11:
** padd.ws\ta[0-9],x0,a[0-9]
** ...
*/
int32x2_t f11 (int32_t x0){
    return __riscv_pmv_s_i32x2(x0);
}