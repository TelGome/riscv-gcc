;); Machine description for RISC-V Bit Manipulation operations.
;; Copyright (C) 2025 Free Software Foundation, Inc.
;; Contributed by Jiawei Chen (jiawei@iscas.ac.cn), PLCT ISCAS.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

;; Packed-SIMD extension.


(define_c_enum "unspec" [
  UNSPEC_CLS
  UNSPEC_REV
  UNSPEC_REV16
  UNSPEC_SHA
  UNSPEC_SHL
  UNSPEC_UNZIP8P
  UNSPEC_PSLLI
  UNSPEC_PSSLAI
  UNSPEC_SSLAI
  UNSPEC_PLI
  UNSPEC_PSEXT
  UNSPEC_PLUI
  UNSPEC_PSLL
  UNSPEC_PADD
  UNSPEC_PSSHA
  UNSPEC_PSSHAR
  UNSPEC_PSSHL
  UNSPEC_PSSHLR
  UNSPEC_PSRL
  UNSPEC_PSRLI
  UNSPEC_PUSATI
  UNSPEC_PSRAI
  UNSPEC_PSATI
  UNSPEC_SATI
  UNSPEC_PSRA
  UNSPEC_PDIFSUMU
  UNSPEC_PDIFSUMAU
  UNSPEC_PMUL
  UNSPEC_PPACK
  UNSPEC_PM2ADD
  UNSPEC_PMULH
  UNSPEC_PSA
  UNSPEC_PMSEQ
  UNSPEC_PAS
])


(define_mode_iterator VQI [(V4QI "!TARGET_64BIT") (V8QI "TARGET_64BIT")])
(define_mode_iterator VHI [(V2HI "!TARGET_64BIT") (V4HI "TARGET_64BIT")])
(define_mode_iterator V_SI [(SI "!TARGET_64BIT") (V2SI "TARGET_64BIT")])
(define_mode_iterator SI_DI [(SI "!TARGET_64BIT") (DI "TARGET_64BIT")])
(define_mode_iterator VPSI [(SI "!TARGET_64BIT") (V2SI "TARGET_64BIT")])
(define_mode_attr PSEXT [(V2HI "V4QI") (V4HI "V8QI")])
(define_mode_iterator VD_SI [(SI "!TARGET_64BIT") (V2SI "TARGET_64BIT")])


(define_mode_iterator VQIHISI [(V4QI "!TARGET_64BIT") (V8QI "TARGET_64BIT")
                            (V2HI "!TARGET_64BIT") (V4HI "TARGET_64BIT")
                            (V2SI "TARGET_64BIT")])

(define_mode_attr SUFFIX [(V4QI "b") (V8QI "b") (V2HI "h") (V4HI "h") (V2SI "w")])
(define_mode_attr PMUL [(V2HI "V4QI") (V4HI "V8QI")])


;Scalar Intrinsics Common to RV32 and RV64
(define_insn "riscv_abs<mode>_p"
  [(set (match_operand:X 0 "register_operand" "=r")
        (abs:X (match_operand:X 1 "register_operand" "r")))]
  "TARGET_RVP"
  "abs\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_cls<mode>_p"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec:X [(match_operand:X 1 "register_operand" "r")]
         UNSPEC_CLS))]
  "TARGET_RVP"
  "cls\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_rev<mode>_p"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec:X [(match_operand:X 1 "register_operand" "r")]
         UNSPEC_REV))]
  "TARGET_RVP"
  "rev\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

;RV64 Only Scalar Intrinsics
(define_insn "riscv_absw_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (sign_extend:DI
          (abs:SI (match_operand:SI 1 "register_operand" "r"))))]
  "TARGET_RVP && TARGET_64BIT"
  "absw\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_clsw_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (sign_extend:DI
          (unspec:SI [(match_operand:SI 1 "register_operand" "r")] UNSPEC_CLS)))]
  "TARGET_RVP && TARGET_64BIT"
  "clsw\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_rev16_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")]
         UNSPEC_REV16))]
  "TARGET_RVP && TARGET_64BIT"
  "rev16\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_sha_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")]
         UNSPEC_SHA))]
  "TARGET_RVP && TARGET_64BIT"
  "sha\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_shar_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")]
         UNSPEC_SHA))]
  "TARGET_RVP && TARGET_64BIT"
  "shar\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_shl_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")]
         UNSPEC_SHL))]
  "TARGET_RVP && TARGET_64BIT"
  "shl\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_shlr_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")]
         UNSPEC_SHA))]
  "TARGET_RVP && TARGET_64BIT"
  "shlr\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Splat
(define_insn "riscv_pmv_s_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   padd.bs\t%0,x0,%1
   pli.b\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pmv_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   padd.bs\t%0,x0,%1
   pli.b\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pmv_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r, r")
        (unspec:V2HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpi, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   padd.hs\t%0,x0,%1
   pli.h\t%0,%1
   plui.h\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pmv_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r, r")
        (unspec:V2HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpi, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   padd.hs\t%0,x0,%1
   pli.h\t%0,%1
   plui.h\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pmv_s_u8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_u8x8_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_u8x8_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_u8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   padd.dbs\t%0,x0,%1
   pli.db\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pmv_s_u8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   padd.bs\t%0,x0,%1
   pli.b\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_pmv_s_i8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_i8x8_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_i8x8_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_i8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   padd.dbs\t%0,x0,%1
   pli.db\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pmv_s_i8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   padd.bs\t%0,x0,%1
   pli.b\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_pmv_s_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_u16x4_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_u16x4_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R, R")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpb, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   padd.dhs\t%0,x0,%1
   pli.dh\t%0,%1
   plui.dh\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pmv_s_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R, R")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpb, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   padd.hs\t%0,x0,%1
   pli.h\t%0,%1
   plui.h\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pmv_s_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_i16x4_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_i16x4_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R, R")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpb, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   padd.dhs\t%0,x0,%1
   pli.dh\t%0,%1
   plui.dh\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pmv_s_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R, R")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpb, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   padd.hs\t%0,x0,%1
   pli.h\t%0,%1
   plui.h\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pmv_s_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_u32x2_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_u32x2_rv32 (operands[0], operands[1]));
  }
  DONE;
})

;TODO lui+addi+mv
(define_insn "riscv_pmv_s_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R, R")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand" "r, Wpb, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.dws\t%0,x0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pmv_s_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R, R")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand" "r, Wpb, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   padd.ws\t%0,x0,%1
   pli.w\t%0,%1
   plui.w\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pmv_s_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_i32x2_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_i32x2_rv32 (operands[0], operands[1]));
  }
  DONE;
})

;TODO lui+addi+mv
(define_insn "riscv_pmv_s_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R, R")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand" "r, Wpb, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.dws\t%0,x0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pmv_s_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R, R")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand" "r, Wpb, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   padd.ws\t%0,x0,%1
   pli.w\t%0,%1
   plui.w\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

; Packed Shifts
(define_insn "riscv_psll_s_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.b\t%0,%1,%2
   psll.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.b\t%0,%1,%2
   psll.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.h\t%0,%1,%2
   psll.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.h\t%0,%1,%2
   psll.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pssha_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psslai.h\t%0,%1,%2
   psrai.h\t%0,%1,%2
   pssha.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_psshar_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
         UNSPEC_PSSHAR))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psslai.h\t%0,%1,%2
   psrari.h\t%0,%1,%n2
   psshar.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_psshl_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:SI 2 "arith_operand" "r")]
         UNSPEC_PSSHL))]
  "TARGET_RVP && !TARGET_64BIT"
  "psshl.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psshlr_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:SI 2 "arith_operand" "r")]
         UNSPEC_PSSHLR))]
  "TARGET_RVP && !TARGET_64BIT"
  "psshlr.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psrl_s_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSRL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrli.b\t%0,%1,%2
   psrl.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psrl_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PSRL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrli.h\t%0,%1,%2
   psrl.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psra_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSRA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrai.b\t%0,%1,%2
   psra.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psra_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PSRA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrai.h\t%0,%1,%2
   psra.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_u8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_u8x8_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_u8x8_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})
 

(define_insn "riscv_psll_s_u8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.db\t%0,%1,%2
   psll.dbs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_u8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.b\t%0,%1,%2
   psll.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_i8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_i8x8_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_i8x8_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_i8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.b\t%0,%1,%2
   psll.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.db\t%0,%1,%2
   psll.dbs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_u16x4_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_u16x4_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.dh\t%0,%1,%2
   psll.dhs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.h\t%0,%1,%2
   psll.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_i16x4_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_i16x4_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.dh\t%0,%1,%2
   psll.dhs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.h\t%0,%1,%2
   psll.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_u32x2_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_u32x2_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u5, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.dw\t%0,%1,%2
   psll.dws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u5, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.w\t%0,%1,%2
   psll.ws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_i32x2_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_i32x2_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u5, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.dw\t%0,%1,%2
   psll.dws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u5, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.w\t%0,%1,%2
   psll.ws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_pssha_s_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pssha_s_i16x4_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_pssha_s_i16x4_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_pssha_s_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R, R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psslai.dh\t%0,%1,%2
   psrai.dh\t%0,%1,%2
   pssha.dhs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pssha_s_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r, r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psslai.h\t%0,%1,%2
   psrai.h\t%0,%1,%2
   pssha.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pssha_s_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u5, w5, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pssha_s_i32x2_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_pssha_s_i32x2_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_pssha_s_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u5, w5, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psslai.dw\t%0,%1,%2
   psrai.dw\t%0,%1,%2
   pssha.dws\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pssha_s_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r, r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u5, w5, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psslai.w\t%0,%1,%2
   psrai.w\t%0,%1,%2
   pssha.ws\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])


