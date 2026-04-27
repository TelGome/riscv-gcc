/* RISC-V 'Packed SIMD' Extension intrinsics include file.
   Copyright (C) 2025 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __RISCV_PACKED_SIMD_H
#define __RISCV_PACKED_SIMD_H

#include <stdint.h>

// #ifndef __riscv_p
// #error "Packed SIMD intrinsics require the rvp extension."
// #endif

typedef signed char int8x4_t __attribute((vector_size(4)));
typedef signed char int8x8_t __attribute((vector_size(8)));
typedef short int16x2_t __attribute((vector_size(4)));
typedef short int16x4_t __attribute__((vector_size(8)));
typedef int int32x2_t __attribute__((vector_size(8)));
typedef unsigned char uint8x4_t __attribute__((vector_size(4)));
typedef unsigned char uint8x8_t __attribute__((vector_size(8)));
typedef unsigned short uint16x2_t __attribute__((vector_size(4)));
typedef unsigned short uint16x4_t __attribute__((vector_size(8)));
typedef unsigned int uint32x2_t __attribute__((vector_size(8)));

typedef uint8_t  uint8x4_t  __attribute__((vector_size(4)));
typedef int8_t   int8x4_t   __attribute__((vector_size(4)));
typedef uint16_t uint16x2_t __attribute__((vector_size(4)));
typedef int16_t  int16x2_t  __attribute__((vector_size(4)));

#if __riscv_xlen == 32
typedef int32_t intXLEN_t;
typedef uint32_t uintXLEN_t;
typedef int32_t int32xN_t;
typedef uint32_t uint32xN_t;
typedef uint16x2_t uint16xN_t;
typedef int16x2_t int16xN_t;
typedef uint8x4_t uint8xN_t;
typedef int8x4_t int8xN_t;
#else
typedef int64_t intXLEN_t;
typedef uint64_t uintXLEN_t;
typedef int32x2_t int32xN_t;
typedef uint32x2_t uint32xN_t;
typedef uint16x4_t uint16xN_t;
typedef int16x4_t int16xN_t;
typedef uint8x8_t uint8xN_t;
typedef int8x8_t int8xN_t;
#endif

#define RVP_INTRINSIC_PREFIX __riscv_
#define RVP_INTRINSIC_VECTOR_PREFIX __riscv_v_

#define RVP_ARGUMENT_LIST(_0, _1, _2, _3, _4, _5, ...) _5
#define RVP_N_ARG(...) RVP_ARGUMENT_LIST(_, ##__VA_ARGS__, 4, 3, 2, 1, 0)

#define RVP_VAR0(...)
#define RVP_VAR1(type1) a
#define RVP_VAR2(type1, type2) RVP_VAR1(type1), b
#define RVP_VAR3(type1, type2, type3) RVP_VAR2(type1, type2), c
#define RVP_VAR4(type1, type2, type3, type4) RVP_VAR3(type1, type2, type3), d

#define RVP_ARG0(...)
#define RVP_ARG1(type1) type1 a
#define RVP_ARG2(type1, type2) RVP_ARG1(type1), type2 b
#define RVP_ARG3(type1, type2, type3) RVP_ARG2(type1, type2), type3 c
#define RVP_ARG4(type1, type2, type3, type4)                                   \
  RVP_ARG3(type1, type2, type3), type4 d

#define RVP_CONCAT_IMPL(x, y) x##y
#define RVP_CONCAT(x, y) RVP_CONCAT_IMPL(x, y)
#define RVP_EXPAND_ARGS(...)                                                   \
  RVP_CONCAT(RVP_ARG, RVP_N_ARG(__VA_ARGS__))(__VA_ARGS__)
#define RVP_EXPAND_VARS(...)                                                   \
  RVP_CONCAT(RVP_VAR, RVP_N_ARG(__VA_ARGS__))(__VA_ARGS__)

#define RVP_VECTOR_BUILTIN_PREFIX __builtin_riscv_v_

#define CREATE_RVP_INTRINSIC(return_type, name, ...)                           \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, name, __riscv_,                  \
                              __builtin_riscv_, RVP_EXPAND_ARGS,               \
                              RVP_EXPAND_VARS, __VA_ARGS__)

#define CREATE_RVP_INTRINSIC_ALIAS(return_type, name, internal_name, ...)      \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, internal_name, __riscv_,         \
                              __builtin_riscv_, RVP_EXPAND_ARGS,               \
                              RVP_EXPAND_VARS, __VA_ARGS__)

/* RVP_N_ARG() expands to 0 in c89 */
#define CREATE_RVP_INTRINSIC_EMPTY_ARGS(return_type, name, ...)                \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, name, RVP_INTRINSIC_PREFIX,   \
                              __builtin_riscv_, RVP_ARG0, RVP_VAR0,            \
                              __VA_ARGS__)

#define CREATE_RVP_INTRINSIC_VECTOR(return_type, name, ...)                    \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, name,                         \
                              RVP_INTRINSIC_VECTOR_PREFIX,                     \
                              RVP_VECTOR_BUILTIN_PREFIX, RVP_EXPAND_ARGS,      \
                              RVP_EXPAND_VARS, __VA_ARGS__)

#define CREATE_RVP_INTRINSIC_VECTOR_ALIAS(return_type, name, internal_name,    \
                                          ...)                                 \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, internal_name,                \
                              RVP_INTRINSIC_VECTOR_PREFIX,                     \
                              RVP_VECTOR_BUILTIN_PREFIX, RVP_EXPAND_ARGS,      \
                              RVP_EXPAND_VARS, __VA_ARGS__)

#define DIRECT_CREATE_RVP_INTRINSIC(return_type, name, internal_name,          \
                                    intrisic_prefix, builtin_prefix,           \
                                    arg_expand_macro, var_expand_macro, ...)   \
  __extension__ extern __inline                                                \
      __attribute__((__always_inline__, __gnu_inline__, __artificial__))       \
      return_type                                                              \
      RVP_CONCAT(intrisic_prefix, name(arg_expand_macro(__VA_ARGS__))) {       \
    return RVP_CONCAT(builtin_prefix,                                          \
                      internal_name)(var_expand_macro(__VA_ARGS__));           \
  }


#ifdef __cplusplus
extern "C" {
#endif

// #if defined (__riscv_rvp)

#define __riscv_pmv_s_u8x8(x) __builtin_riscv_pmv_s_u8x8((uint8_t)(x))
#define __riscv_pmv_s_i8x8(x) __builtin_riscv_pmv_s_i8x8((int8_t)(x))
#define __riscv_pmv_s_u16x4(x) __builtin_riscv_pmv_s_u16x4((uint16_t)(x))
#define __riscv_pmv_s_i16x4(x) __builtin_riscv_pmv_s_i16x4((int16_t)(x))
#define __riscv_pmv_s_u32x2(x) __builtin_riscv_pmv_s_u32x2((uint32_t)(x))
#define __riscv_pmv_s_i32x2(x) __builtin_riscv_pmv_s_i32x2((int32_t)(x))

CREATE_RVP_INTRINSIC(uintXLEN_t, abs, intXLEN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, cls, intXLEN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, rev, uintXLEN_t)

CREATE_RVP_INTRINSIC(uint8x8_t, psll_s_u8x8, uint8x8_t, uint32_t)

#if __riscv_xlen == 32

// Packed Splat
// CREATE_RVP_INTRINSIC(uint8x4_t, pmv_s_u8x4,uint8_t)
// CREATE_RVP_INTRINSIC(int8x4_t, pmv_s_i8x4, int8_t)
// CREATE_RVP_INTRINSIC(uint16x2_t, pmv_s_u16x2, uint16_t)
// CREATE_RVP_INTRINSIC(int16x2_t, pmv_s_i16x2, int16_t)
#define __riscv_pmv_s_u8x4(x) __builtin_riscv_pmv_s_u8x4((uint8_t)(x))
#define __riscv_pmv_s_i8x4(x) __builtin_riscv_pmv_s_i8x4((int8_t)(x))
#define __riscv_pmv_s_u16x2(x) __builtin_riscv_pmv_s_u16x2((uint16_t)(x))
#define __riscv_pmv_s_i16x2(x) __builtin_riscv_pmv_s_i16x2((int16_t)(x))

// Packed Shifts
CREATE_RVP_INTRINSIC(uint8x4_t, psll_s_u8x4, uint8x4_t, uint32_t)
CREATE_RVP_INTRINSIC(int8x4_t, psll_s_i8x4, int8x4_t, uint32_t)
CREATE_RVP_INTRINSIC(uint16x2_t, psll_s_u16x2, uint16x2_t, uint32_t)
CREATE_RVP_INTRINSIC(int16x2_t, psll_s_i16x2, int16x2_t, uint32_t)
CREATE_RVP_INTRINSIC(int16x2_t, pssha_s_i16x2, int16x2_t, int32_t)
CREATE_RVP_INTRINSIC(int16x2_t, psshar_s_i16x2, int16x2_t, int32_t)
CREATE_RVP_INTRINSIC(uint16x2_t, psshl_s_u16x2, uint16x2_t, int32_t)
CREATE_RVP_INTRINSIC(uint16x2_t, psshlr_s_u16x2, uint16x2_t, int32_t)
CREATE_RVP_INTRINSIC(uint8x4_t, psrl_s_u8x4, uint8x4_t, uint32_t)
CREATE_RVP_INTRINSIC(uint16x2_t, psrl_s_u16x2, uint16x2_t, uint32_t)
CREATE_RVP_INTRINSIC(int8x4_t, psra_s_i8x4, int8x4_t, uint32_t)
CREATE_RVP_INTRINSIC(int16x2_t, psra_s_i16x2, int16x2_t, uint32_t)


#endif


#if __riscv_xlen == 64

// RV64 Only Scalar Intrinsics
CREATE_RVP_INTRINSIC(uint64_t, absw, int32_t)
CREATE_RVP_INTRINSIC(uint64_t, clsw, int32_t)
CREATE_RVP_INTRINSIC(uint64_t, rev16, uint64_t)
CREATE_RVP_INTRINSIC(int64_t, sha, int64_t, int)
CREATE_RVP_INTRINSIC(int64_t, shar, int64_t, int)
CREATE_RVP_INTRINSIC(uint64_t, shl, uint64_t, int)
CREATE_RVP_INTRINSIC(uint64_t, shlr, uint64_t, int)


#endif

// #endif // __riscvrvp

#if defined (__cplusplus)
}
#endif // __cplusplus
#endif // __RISCV_PACKED_SIMD_H
