/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** padd.bs\ta[0-9],x0,a[0-9]
** ...
*/

int8x4_t f0 (int8_t x0){
    return __riscv_pmv_s_i8x4(x0);
}

/*
**f1:
** padd.bs\ta[0-9],x0,a[0-9]
** ...
*/
uint8x4_t f1 (uint8_t x0){
    return __riscv_pmv_s_u8x4(x0);
}

/*
**f2:
** pli.b\ta[0-9],1
** ...
*/

int8x4_t f2 (int8_t x0){
    return __riscv_pmv_s_i8x4(1);
}

/*
**f3:
** pli.b\ta[0-9],1
** ...
*/
uint8x4_t f3 (uint8_t x0){
    return __riscv_pmv_s_u8x4(1);
}

/*
**f4:
** padd.hs\ta[0-9],x0,a[0-9]
** ...
*/
uint16x2_t f4 (uint16_t x0){
    return __riscv_pmv_s_u16x2(x0);
}

/*
**f5:
** pli.h\ta[0-9],1
** ...
*/
uint16x2_t f5 (uint16_t x0){
    return __riscv_pmv_s_u16x2(1);
}

/*
**f6:
** plui.h\ta[0-9],1024
** ...
*/
uint16x2_t f6 (uint16_t x0){
    return __riscv_pmv_s_u16x2(1024);
}

/*
**f7:
** padd.hs\ta[0-9],x0,a[0-9]
** ...
*/
int16x2_t f7 (int16_t x0){
    return __riscv_pmv_s_i16x2(x0);
}

/*
**f8:
** pli.h\ta[0-9],1
** ...
*/
int16x2_t f8 (int16_t x0){
    return __riscv_pmv_s_i16x2(1);
}

/*
**f9:
** plui.h\ta[0-9],1024
** ...
*/
int16x2_t f9 (int16_t x0){
    return __riscv_pmv_s_i16x2(1024);
}

/*
**f10:
** padd.dbs\ta[0-9],x0,a[0-9]
** ...
*/
uint8x8_t f10 (uint8_t x0){
    return __riscv_pmv_s_u8x8(x0);
}

/*
**f11:
** pli.db\ta[0-9],1
** ...
*/
uint8x8_t f11 (uint8_t x0){
    return __riscv_pmv_s_u8x8(1);
}

/*
**f12:
** padd.dbs\ta[0-9],x0,a[0-9]
** ...
*/
int8x8_t f12 (int8_t x0){
    return __riscv_pmv_s_i8x8(x0);
}

/*
**f13:
** pli.db\ta[0-9],1
** ...
*/
int8x8_t f13 (int8_t x0){
    return __riscv_pmv_s_i8x8(1);
}

/*
**f14:
** padd.dhs\ta[0-9],x0,a[0-9]
** ...
*/
uint16x4_t f14 (uint16_t x0){
    return __riscv_pmv_s_u16x4(x0);
}

/*
**f15:
** pli.dh\ta[0-9],1
** ...
*/
uint16x4_t f15 (uint16_t x0){
    return __riscv_pmv_s_u16x4(1);
}

/*
**f16:
** plui.dh\ta[0-9],1024
** ...
*/
uint16x4_t f16 (uint16_t x0){
    return __riscv_pmv_s_u16x4(1024);
}

/*
**f17:
** padd.dhs\ta[0-9],x0,a[0-9]
** ...
*/
int16x4_t f17 (int16_t x0){
    return __riscv_pmv_s_i16x4(x0);
}

/*
**f18:
** pli.dh\ta[0-9],1
** ...
*/
int16x4_t f18 (int16_t x0){
    return __riscv_pmv_s_i16x4(1);
}

/*
**f19:
** plui.dh\ta[0-9],1024
** ...
*/
int16x4_t f19 (int16_t x0){
    return __riscv_pmv_s_i16x4(1024);
}

/*
**f20:
** padd.dws\ta[0-9],x0,a[0-9]
** ...
*/
uint32x2_t f20 (uint32_t x0){
    return __riscv_pmv_s_u32x2(x0);
}

/*
**f21:
** padd.dws\ta[0-9],x0,a[0-9]
** ...
*/
int32x2_t f21 (int32_t x0){
    return __riscv_pmv_s_i32x2(x0);
}