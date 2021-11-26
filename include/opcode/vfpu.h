#ifndef _VFPU_H_
#define _VFPU_H_

static const struct
{
  unsigned int encoded_expr[3];  // Three possible sizes
  unsigned int imm5;             // The actual instruction encoding
} vrot_enct[16] = {
  {{14, 58, 234},  0},  // csss
  {{11, 44, 176},  1},  // sc00
  {{ 8, 35, 140},  2},  // s0c0
  {{ 8, 32, 131},  3},  // s00c
  {{14, 56, 224},  4},  // cs00
  {{11, 46, 186},  5},  // scss
  {{ 2, 11,  44},  6},  // 0sc0
  {{ 2,  8,  35},  7},  // 0s0c
  {{12, 50, 200},  8},  // c0s0
  {{ 3, 14,  56},  9},  // 0cs0
  {{10, 43, 174}, 10},  // sscs
  {{ 0,  2,  11}, 11},  // 00sc
  {{12, 48, 194}, 12},  // c00s
  {{ 3, 12,  50}, 13},  // 0c0s
  {{ 0,  3,  14}, 14},  // 00cs
  {{10, 42, 171}, 15},  // sssc
};

static const char * const vrot_dect[32][4] = {
  {"c", "s", "s", "s"},
  {"s", "c", "0", "0"},
  {"s", "0", "c", "0"},
  {"s", "0", "0", "c"},
  {"c", "s", "0", "0"},
  {"s", "c", "s", "s"},
  {"0", "s", "c", "0"},
  {"0", "s", "0", "c"},
  {"c", "0", "s", "0"},
  {"0", "c", "s", "0"},
  {"s", "s", "c", "s"},
  {"0", "0", "s", "c"},
  {"c", "0", "0", "s"},
  {"0", "c", "0", "s"},
  {"0", "0", "c", "s"},
  {"s", "s", "s", "c"},
  {"c", "-s", "-s", "-s"},
  {"-s", "c", "0", "0"},
  {"-s", "0", "c", "0"},
  {"-s", "0", "0", "c"},
  {"c", "-s", "0", "0"},
  {"-s", "c", "-s", "-s"},
  {"0", "-s", "c", "0"},
  {"0", "-s", "0", "c"},
  {"c", "0", "-s", "0"},
  {"0", "c", "-s", "0"},
  {"-s", "-s", "c", "-s"},
  {"0", "0", "-s", "c"},
  {"c", "0", "0", "-s"},
  {"0", "c", "0", "-s"},
  {"0", "0", "c", "-s"},
  {"-s", "-s", "-s", "c"},
};

#define VFPU_CONDCODE_FL    0
#define VFPU_CONDCODE_EQ    1
#define VFPU_CONDCODE_LT    2
#define VFPU_CONDCODE_LE    3
#define VFPU_CONDCODE_TR    4
#define VFPU_CONDCODE_NE    5
#define VFPU_CONDCODE_GE    6
#define VFPU_CONDCODE_GT    7
#define VFPU_CONDCODE_EZ    8
#define VFPU_CONDCODE_EN    9
#define VFPU_CONDCODE_EI   10
#define VFPU_CONDCODE_ES   11
#define VFPU_CONDCODE_NZ   12
#define VFPU_CONDCODE_NN   13
#define VFPU_CONDCODE_NI   14
#define VFPU_CONDCODE_NS   15


#define VF_BITCNT_VT     7
#define VF_SH_VT       16
#define VF_BITCNT_VS     7
#define VF_SH_VS       8
#define VF_BITCNT_VD     7
#define VF_SH_VD       0
#define VF_BITCNT_VML        5
#define VF_MASK_VML        0x1f
#define VF_SH_VML      16
#define VF_BITCNT_VMH        2
#define VF_MASK_VMH        0x3
#define VF_SH_VMH      0
#define VF_BITCNT_VNL        5
#define VF_MASK_VNL        0x1f
#define VF_SH_VNL      16
#define VF_BITCNT_VNH        1
#define VF_MASK_VNH        0x1
#define VF_SH_VNH      0
#define VF_BITCNT_OFFSET     14
#define VF_MASK_OFFSET     0x3fff
#define VF_SH_OFFSET       2
#define VF_BITCNT_CC    4
#define VF_SH_CC       0
#define VF_BITCNT_CONST      5
#define VF_SH_CONST        16
#define VF_BITCNT_SCALE      5
#define VF_SH_SCALE        16
#define VF_BITCNT_BCOND      3
#define VF_SH_BCOND        18
#define VF_BITCNT_MCOND      3
#define VF_MASK_MCOND      0x7
#define VF_SH_MCOND        16
#define VF_BITCNT_VCD        8
#define VF_SH_VCD      0
#define VF_BITCNT_VCS        8
#define VF_SH_VCS      8
#define VF_BITCNT_ROT        5
#define VF_SH_ROT      16
#define VF_BITCNT_WRAP       8
#define VF_SH_WRAP     16
#define VF_SH_BMCOND       0
#define VF_BITCNT_HFLOAT     16
#define VF_SH_HFLOAT       0
#define VF_BITCNT_PFX       24
#define VF_SH_PFX       0
#define VF_BITCNT_RWB        0x1
#define VF_SH_RWB      1

#define    VF_MASK_PFX_SWZ     0x3
#define    VF_SH_PFX_SWZ       0
#define    VF_MASK_PFX_ABS     0x1
#define    VF_SH_PFX_ABS       8
#define    VF_MASK_PFX_CST     0x1
#define    VF_SH_PFX_CST       12
#define    VF_MASK_PFX_NEG     0x1
#define    VF_SH_PFX_NEG       16
#define    VF_MASK_PFX_SAT     0x3
#define    VF_SH_PFX_SAT       0
#define    VF_MASK_PFX_MSK     0x1
#define    VF_SH_PFX_MSK       8

#define    VF_MASK_MR_MTX      0x7
#define    VF_SH_MR_MTX        2
#define    VF_MASK_MR_IDX      0x3
#define    VF_SH_MR_IDX        0
#define    VF_MASK_MR_FSL      0x3
#define    VF_SH_MR_FSL        5
#define    VF_MASK_MR_RXC      0x1
#define    VF_SH_MR_RXC        5
#define    VF_MASK_MR_VFSL     0x1
#define    VF_SH_MR_VFSL       6

#define    VF_MIN_MR       0
#define    VF_MAX_MR       127
#define    VF_MIN_CR       128
#define    VF_MAX_CR       255
#define    VF_MIN_VCR      128
#define    VF_MAX_VCR      143
#define    VF_MIN_CC       0
#define    VF_MAX_CC       15
#define    VF_MIN_CONST        1
#define    VF_MAX_CONST        19
#define    VF_MIN_SCALE        0
#define    VF_MAX_SCALE        31
#define    VF_MIN_BCOND        0
#define    VF_MAX_BCOND        5
#define    VF_MIN_MCOND        0
#define    VF_MAX_MCOND        6
#define    VF_MIN_WRAP     0
#define    VF_MAX_WRAP     255
#define    VF_MIN_BMCOND       0
#define    VF_MAX_BMCOND       31

#define    VF_MASK_F32_SIGN    0x1
#define    VF_SH_F32_SIGN      31
#define    VF_MASK_F32_EXP     0xff
#define    VF_SH_F32_EXP       23
#define    VF_MASK_F32_FRA     0x7fffff
#define    VF_SH_F32_FRA       0
#define    VF_MASK_F16_SIGN    0x1
#define    VF_SH_F16_SIGN      15
#define    VF_MASK_F16_EXP     0x1f
#define    VF_SH_F16_EXP       10
#define    VF_MASK_F16_FRA     0x3ff
#define    VF_SH_F16_FRA       0

#define    VF_MIN_F32_EXP      0
#define    VF_MAX_F32_EXP      255
#define    VF_BIAS_F32_EXP     127
#define    VF_MIN_F16_EXP      0
#define    VF_MAX_F16_EXP      31
#define    VF_BIAS_F16_EXP     15

#define OP_SH_VFPU_DELTA   0
#define OP_MASK_VFPU_DELTA 0xfffc
#define OP_SH_VFPU_IMM3        16
#define OP_MASK_VFPU_IMM3  0x7
#define OP_SH_VFPU_IMM5        16
#define OP_MASK_VFPU_IMM5  0x1f
#define OP_SH_VFPU_IMM8        16
#define OP_MASK_VFPU_IMM8  0xff
#define OP_SH_VFPU_CC      18  /* Condition code. */
#define OP_MASK_VFPU_CC        0x7
#define OP_SH_VFPU_CONST   16
#define OP_MASK_VFPU_CONST 0x1f
#define OP_SH_VFPU_COND        0   /* Conditional compare. */
#define OP_MASK_VFPU_COND  0xf
#define OP_SH_VFPU_VMTVC   0
#define OP_MASK_VFPU_VMTVC 0xff
#define OP_SH_VFPU_VMFVC   8
#define OP_MASK_VFPU_VMFVC 0xff
#define OP_SH_VFPU_RWB     1
#define OP_MASK_VFPU_RWB   0x1
#define OP_SH_VFPU_ROT     16  /* Rotators used in vrot. */
#define OP_MASK_VFPU_ROT   0x1f
#define OP_SH_VFPU_FLOAT16 0
#define OP_MASK_VFPU_FLOAT16   0xffff

/* VFPU registers. */
#define OP_SH_VFPU_VD      0
#define OP_MASK_VFPU_VD        0x7f
#define OP_SH_VFPU_VS      8
#define OP_MASK_VFPU_VS        0x7f
#define OP_SH_VFPU_VT      16
#define OP_MASK_VFPU_VT        0x7f
#define OP_SH_VFPU_VT_LO   16  /* Bits 0-4 of vt. */
#define OP_MASK_VFPU_VT_LO 0x1f
#define OP_SH_VFPU_VT_HI   5   /* Right-shifted. */
#define OP_MASK_VFPU_VT_HI1    0x1 /* Bit 5 of vt. */
#define OP_MASK_VFPU_VT_HI2    0x3 /* Bits 5-6 of vt. */
/* Special handling of vs in vmmul instructions. */
#define VFPU_OP_VT_VS_VD   0xff800000
#define VFPU_OPCODE_VMMUL  0xf0000000

/* VFPU condition codes.  FL and TR accept no arguments, while any conditions
   above and including EZ only accept one argument.  The rest require two
   arguments.  */
enum
{
  VFPU_COND_FL, VFPU_COND_EQ, VFPU_COND_LT, VFPU_COND_LE,
  VFPU_COND_TR, VFPU_COND_NE, VFPU_COND_GE, VFPU_COND_GT,
  VFPU_COND_EZ, VFPU_COND_EN, VFPU_COND_EI, VFPU_COND_ES,
  VFPU_COND_NZ, VFPU_COND_NN, VFPU_COND_NI, VFPU_COND_NS,
  VFPU_NUM_CONDS
};

/* VFPU prefix instruction operands.  The *_SH_* values really specify where
   the bitfield begins, as VFPU prefix instructions have four operands
   encoded within the immediate field. */
#define VFPU_SH_PFX_NEG        16
#define VFPU_MASK_PFX_NEG  0x1 /* Negation. */
#define VFPU_SH_PFX_CST        12
#define VFPU_MASK_PFX_CST  0x1 /* Constant. */
#define VFPU_SH_PFX_ABS_CSTHI  8
#define VFPU_MASK_PFX_ABS_CSTHI    0x1 /* Abs/Constant (bit 2). */
#define VFPU_SH_PFX_SWZ_CSTLO  0
#define VFPU_MASK_PFX_SWZ_CSTLO    0x3 /* Swizzle/Constant (bits 0-1). */
#define VFPU_SH_PFX_MASK   8
#define VFPU_MASK_PFX_MASK 0x1 /* Mask. */
#define VFPU_SH_PFX_SAT        0
#define VFPU_MASK_PFX_SAT  0x3 /* Saturation. */

/* VFPU 16-bit floating-point format. */
#define VFPU_FLOAT16_EXP_MAX   0x1f
#define VFPU_SH_FLOAT16_SIGN   15
#define VFPU_MASK_FLOAT16_SIGN 0x1
#define VFPU_SH_FLOAT16_EXP    10
#define VFPU_MASK_FLOAT16_EXP  0x1f
#define VFPU_SH_FLOAT16_FRAC   0
#define VFPU_MASK_FLOAT16_FRAC 0x3ff

#endif /* _VFPU_H_ */
