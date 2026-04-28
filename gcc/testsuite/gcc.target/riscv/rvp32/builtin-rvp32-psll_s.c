/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pslli.b\ta[0-9],a[0-9],1
** ...
*/
uint8x4_t f0 (uint8x4_t x0, uint32_t x1){
    return __riscv_psll_s_u8x4(x0, 1);
}

/*
**f1:
** psll.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint8x4_t f1 (uint8x4_t x0, uint32_t x1){
    return __riscv_psll_s_u8x4(x0, x1);
}

/*
**f2:
** pslli.b\ta[0-9],a[0-9],1
** ...
*/
int8x4_t f2 (int8x4_t x0, uint32_t x1){
    return __riscv_psll_s_i8x4(x0, 1);
}

/*
**f3:
** psll.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/
int8x4_t f3 (int8x4_t x0, uint32_t x1){
    return __riscv_psll_s_i8x4(x0, x1);
}

/*
**f4:
** pslli.h\ta[0-9],a[0-9],1
** ...
*/
uint16x2_t f4 (uint16x2_t x0, uint32_t x1){
    return __riscv_psll_s_u16x2(x0, 1);
}

/*
**f5:
** psll.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint16x2_t f5 (uint16x2_t x0, uint32_t x1){
    return __riscv_psll_s_u16x2(x0, x1);
}

/*
**f6:
** pslli.h\ta[0-9],a[0-9],1
** ...
*/
int16x2_t f6 (int16x2_t x0, uint32_t x1){
    return __riscv_psll_s_i16x2(x0, 1);
}

/*
**f7:
** psll.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/
int16x2_t f7 (int16x2_t x0, uint32_t x1){
    return __riscv_psll_s_i16x2(x0, x1);
}

/*
**f8:
** pssha.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/
int16x2_t f8 (int16x2_t x0, int32_t x1){
    return __riscv_pssha_s_i16x2(x0, x1);
}

/*
**f9:
** psslai.h\ta[0-9],a[0-9],5
** ...
*/
int16x2_t f9 (int16x2_t x0, int32_t x1){
    return __riscv_pssha_s_i16x2(x0, 5);
}

/*
**f10:
** psrai.h\ta[0-9],a[0-9],-5
** ...
*/
int16x2_t f10 (int16x2_t x0, int32_t x1){
    return __riscv_pssha_s_i16x2(x0, -5);
}

/*
**f11:
** psshar.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/
int16x2_t f11 (int16x2_t x0, int32_t x1){
    return __riscv_psshar_s_i16x2(x0, x1);
}

/*
**f12:
** psslai.h\ta[0-9],a[0-9],5
** ...
*/
int16x2_t f12 (int16x2_t x0, int32_t x1){
    return __riscv_psshar_s_i16x2(x0, 5);
}

/*
**f13:
** psrari.h\ta[0-9],a[0-9],-5
** ...
*/
int16x2_t f13 (int16x2_t x0, int32_t x1){
    return __riscv_psshar_s_i16x2(x0, -5);
}

/*
**f14:
** psshl.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint16x2_t f14 (uint16x2_t x0, int32_t x1){
    return __riscv_psshl_s_u16x2(x0, x1);
}

/*
**f15:
** psshlr.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint16x2_t f15 (uint16x2_t x0, int32_t x1){
    return __riscv_psshlr_s_u16x2(x0, x1);
}

/*
**f16:
** psrli.b\ta[0-9],a[0-9],1
** ...
*/
uint8x4_t f16 (uint8x4_t x0, uint32_t x1){
    return __riscv_psrl_s_u8x4(x0, 1);
}

/*
**f17:
** psrl.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint8x4_t f17 (uint8x4_t x0, uint32_t x1){
    return __riscv_psrl_s_u8x4(x0, x1);
}

/*
**f18:
** psrli.h\ta[0-9],a[0-9],1
** ...
*/
uint16x2_t f18 (uint16x2_t x0, uint32_t x1){
    return __riscv_psrl_s_u16x2(x0, 1);
}

/*
**f19:
** psrl.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint16x2_t f19 (uint16x2_t x0, uint32_t x1){
    return __riscv_psrl_s_u16x2(x0, x1);
}

/*
**f20:
** psrai.b\ta[0-9],a[0-9],1
** ...
*/
int8x4_t f20 (int8x4_t x0, uint32_t x1){
    return __riscv_psra_s_i8x4(x0, 1);
}

/*
**f21:
** psra.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/
int8x4_t f21 (int8x4_t x0, uint32_t x1){
    return __riscv_psra_s_i8x4(x0, x1);
}

/*
**f22:
** psrai.h\ta[0-9],a[0-9],1
** ...
*/
int16x2_t f22 (int16x2_t x0, uint32_t x1){
    return __riscv_psra_s_i16x2(x0, 1);
}

/*
**f23:
** psra.hs\ta[0-9],a[0-9],1
** ...
*/
int16x2_t f23 (int16x2_t x0, uint32_t x1){
    return __riscv_psra_s_i16x2(x0, x1);
}

/*
**f24:
** pslli.db\ta[0-9],a[0-9],1
** ...
*/
uint8x8_t f24 (uint8x8_t x0, uint32_t x1){
    return __riscv_psll_s_u8x8(x0, 1);
}

/*
**f25:
** psll.dbs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint8x8_t f25 (uint8x8_t x0, uint32_t x1){
    return __riscv_psll_s_u8x8(x0, x1);
}

/*
**f26:
** pslli.db\ta[0-9],a[0-9],1
** ...
*/
int8x8_t f26 (int8x8_t x0, uint32_t x1){
    return __riscv_psll_s_i8x8(x0, 1);
}

/*
**f27:
** psll.dbs\ta[0-9],a[0-9],a[0-9]
** ...
*/
int8x8_t f27 (int8x8_t x0, uint32_t x1){
    return __riscv_psll_s_i8x8(x0, x1);
}

/*
**f28:
** pslli.dh\ta[0-9],a[0-9],1
** ...
*/
uint16x4_t f28 (uint16x4_t x0, uint32_t x1){
    return __riscv_psll_s_u16x4(x0, 1);
}

/*
**f29:
** psll.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/
uint16x4_t f29 (uint16x4_t x0, uint32_t x1){
    return __riscv_psll_s_u16x4(x0, x1);
}

/*
**f30:
** pslli.dh\ta[0-9],a[0-9],1
** ...
*/
int16x4_t f30 (int16x4_t x0, uint32_t x1){
    return __riscv_psll_s_i16x4(x0, 1);
}

/*
**f31:
** psll.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/
int16x4_t f31 (int16x4_t x0, uint32_t x1){
    return __riscv_psll_s_i16x4(x0, x1);
}

/*
**f32:
** pslli.dw\ta[0-9],a[0-9],1
** ...
*/
uint32x2_t f32 (uint32x2_t x0, uint32_t x1){
    return __riscv_psll_s_u32x2(x0, 1);
}

/*
**f33:
** psll.dws\ta[0-9],a[0-9],1
** ...
*/
uint32x2_t f33 (uint32x2_t x0, uint32_t x1){
    return __riscv_psll_s_u32x2(x0, x1);
}

/*
**f34:
** pslli.dw\ta[0-9],a[0-9],1
** ...
*/
int32x2_t f34 (int32x2_t x0, uint32_t x1){
    return __riscv_psll_s_i32x2(x0, 1);
}

/*
**f35:
** psll.dws\ta[0-9],a[0-9],1
** ...
*/
int32x2_t f35 (int32x2_t x0, uint32_t x1){
    return __riscv_psll_s_i32x2(x0, x1);
}

