/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
   unsigned exp = (uf >> 23) & 0xFF;
   unsigned frac = uf & 0x7FFFFF;
   if ((exp == 0xFF) && (frac != 0)) {
       return uf;
   }
   return uf & 0x7FFFFFFF;
}

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/* Fixed floatFloat2Int (conforms to Data Lab floating-point rules) */
/* dlc-friendly floatFloat2Int */
int floatFloat2Int(unsigned uf) {
    unsigned sign;
    unsigned exp;
    unsigned frac;
    int E;
    unsigned M;
    unsigned uresult;
    int result;

    /* extract fields */
    sign = uf >> 31;
    exp  = (uf >> 23) & 0xFFu;
    frac = uf & 0x7FFFFFu;

    /* NaN or +/−Inf -> out of range */
    if (exp == 0xFFu) {
        return 0x80000000u;
    }

    /* E = exponent - bias(127) */
    E = exp - 127;

    /* magnitude < 1 -> rounds to 0 */
    if (E < 0) {
        return 0;
    }

    /* too large to represent in 32-bit int */
    if (E > 31) {
        return 0x80000000u;
    }

    /* significand: implicit 1 for normalized numbers */
    M = frac;
    if (exp != 0u) {
        M = frac | 0x800000u;
    }

    /* compute integer magnitude */
    if (E > 23) {
        /* E-23 in range 1..8 when E<=31 -> safe left shift */
        uresult = M << (E - 23);
    } else {
        /* 23-E in range 0..23 -> safe right shift */
        uresult = M >> (23 - E);
    }

    /* special-case exact -2^31 possibility when E==31 */
    if (E == 31) {
        if (sign == 0u) {
            return 0x80000000u;
        }
        if (M != (1u << 23)) {
            return 0x80000000u;
        }
        /* else fall through: exact -2^31 */
    }

    result = uresult;
    if (sign) {
        result = -result;
    }
    return result;
}




/* 
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/* dlc-friendly unsigned floatInt2Float (all declarations first, C-style comments) */
/* dlc-friendly unsigned floatInt2Float (no casts, fewer operators) */
/* Compact dlc-friendly unsigned floatInt2Float
 * - No casts
 * - Declarations first
 * - Reduced temporaries to lower operator count
 */
/* dlc-friendly unsigned floatInt2Float (no casts, reduced operators) */
/* tighter dlc-friendly unsigned floatInt2Float */
/* Reduced-operator, dlc-friendly unsigned floatInt2Float
 * - No casts
 * - Declarations first
 * - Compact expressions to reduce operator count
 */
/* Further reduced-operator unsigned floatInt2Float */
unsigned floatInt2Float(int x) {
    unsigned ux, sign, mant, exp, rem;
    int msb, E, shift;

    if (x == 0) return 0u;

    sign = 0u;
    ux = x;
    if (x < 0) { sign = 1u; ux = -ux; }

    msb = 31;
    while ((ux >> msb) == 0u) msb--;

    E = msb;
    exp = E + 127u;

    if (E > 23) {
        shift = E - 23;
        rem = ux & ((1u << shift) - 1u);
        mant = ux >> shift;
        /* round-to-even compacted: increment when rem > half OR rem == half && LSB==1
           expressed as (rem + (mant&1) > half) to save operators */
        if (rem + (mant & 1u) > (1u << (shift - 1))) {
            mant = mant + 1u;
            if (mant & (1u << 24)) { mant = mant >> 1; exp = exp + 1u; }
        }
    } else {
        mant = ux << (23 - E);
    }

    mant = mant & 0x7FFFFFu;
    return (sign << 31) | (exp << 23) | mant;
}




/* 
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {
    unsigned exp_uf  = (uf >> 23) & 0xFF;
    unsigned frac_uf = uf & 0x7FFFFF;
    unsigned exp_ug  = (ug >> 23) & 0xFF;
    unsigned frac_ug = ug & 0x7FFFFF;

    /* If either is NaN -> false */
    if ( ((exp_uf == 0xFF) && (frac_uf != 0)) ||
         ((exp_ug == 0xFF) && (frac_ug != 0)) )
        return 0;

    /* Exact same bit pattern -> true */
    if (uf == ug)
        return 1;

    /* +0 and -0 are equal */
    if ( ((uf & 0x7FFFFFFF) == 0) && ((ug & 0x7FFFFFFF) == 0) )
        return 1;

    return 0;
}


/* 
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
    unsigned sign_u = uf >> 31;
    unsigned sign_g = ug >> 31;
    unsigned exp_u  = (uf >> 23) & 0xFF;
    unsigned frac_u = uf & 0x7FFFFF;
    unsigned exp_g  = (ug >> 23) & 0xFF;
    unsigned frac_g = ug & 0x7FFFFF;

    /* NaN check */
    if ((exp_u == 0xFF && frac_u != 0) || (exp_g == 0xFF && frac_g != 0))
        return 0;

    /* +0 and -0 are equal */
    if ((uf & 0x7FFFFFFF) == 0 && (ug & 0x7FFFFFFF) == 0)
        return 0;

    /* Different signs */
    if (sign_u != sign_g)
        return sign_u;  /* if uf negative and ug positive -> true */

    /* Same sign */
    if (sign_u == 0)
        return uf < ug; /* both positive: smaller bit pattern => smaller value */
    else
        return uf > ug; /* both negative: reversed ordering */
}

/* 
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
    unsigned exp = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;

    /* NaN check: exponent = 255 and fraction != 0 */
    if (exp == 0xFF && frac != 0)
        return uf;

    /* Flip the sign bit */
    return uf ^ 0x80000000;
}

/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
#include <stdint.h>

unsigned floatPower2(int x) {
    /* Too small to be represented as denormals */
    if (x < -149) {
        return 0u;
    }

    /* Denormalized range: -149 .. -127  -> fraction only */
    if (x <= -127) {
        /* shift amount is 0..22 (safe) */
        unsigned shift = x + 149;        /* 0..22 */
        return 1u << shift;                          /* denorm bitpattern */
    }

    /* Normalized range: -126 .. 127 */
    if (x <= 127) {
        unsigned exp = x + 127;         /* 1..254 */
        return exp << 23;                           /* exponent in bits 30..23 */
    }

    /* Too large -> +INF */
    return 0x7F800000u;
}


/* 
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf) {
    unsigned sign = uf & 0x80000000u;
    unsigned exp  = (uf >> 23) & 0xFFu;
    unsigned frac = uf & 0x7FFFFFu;

    /* NaN or infinity: return argument */
    if (exp == 0xFFu) return uf;

    /* Denormalized: shift fraction right by 1 with round-to-even */
    if (exp == 0u) {
        /* round: add 1 if low two bits are '11' (tie and LSB=1 -> round up) */
        unsigned round = ((frac & 3u) == 3u) ? 1u : 0u;
        frac = (frac >> 1) + round;
        return sign | frac; /* exp is zero */
    }

    /* Normalized case: decrement exponent.
       If exponent becomes zero we must form a denormal: include hidden 1 then shift. */
    exp = exp - 1u;
    if (exp == 0u) {
        /* include implicit 1 at bit 23, then shift right by 1 with rounding */
        unsigned mant = (1u << 23) | frac;       /* 24-bit mantissa */
        unsigned round = ((mant & 3u) == 3u) ? 1u : 0u;
        unsigned new_frac = (mant >> 1) + round; /* result fits into 23 bits */
        return sign | (new_frac & 0x7FFFFFu);    /* denormal (exp==0) */
    }

    /* Still normalized: just pack sign, exp, frac */
    return sign | (exp << 23) | frac; 
}


/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned sign = uf & 0x80000000;
    unsigned exp  = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;

    /* NaN or infinity → return unchanged */
    if (exp == 0xFF) {
        return uf;
    }

    /* Denormalized: exponent = 0, just scale mantissa */
    if (exp == 0) {
        frac <<= 1;
        return sign | frac;
    }

    /* Normalized: bump the exponent */
    exp++;

    /* Overflow to infinity */
    if (exp == 0xFF) {
        return sign | 0x7F800000;
    }

    return sign | (exp << 23) | frac;
}

/* 
 * floatScale4 - Return bit-level equivalent of expression 4*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale4(unsigned uf) {
    unsigned sign = uf & 0x80000000u;
    unsigned exp  = (uf >> 23) & 0xFFu;
    unsigned frac = uf & 0x7FFFFFu;

    /* NaN or infinity -> unchanged */
    if (exp == 0xFFu) return uf;

    /* Denormalized: shift fraction left by 2; may become normalized */
    if (exp == 0u) {
        unsigned shifted = frac << 2; /* up to bit 24 set */

        if (shifted & (1u << 24)) {
            /* bit 24 set -> normalize by shifting right 1, exponent = 2 */
            unsigned new_exp = 2u; /* biased exponent field = 2 */
            unsigned new_frac = (shifted >> 1) & 0x7FFFFFu;
            return sign | (new_exp << 23) | new_frac;
        } else if (shifted & (1u << 23)) {
            /* bit 23 set -> normalize, exponent = 1 */
            unsigned new_exp = 1u;
            unsigned new_frac = shifted & 0x7FFFFFu;
            return sign | (new_exp << 23) | new_frac;
        } else {
            /* still denormal */
            return sign | shifted;
        }
    }

    /* Normalized: add 2 to exponent, check overflow */
    if (exp + 2u >= 0xFFu) {
        return sign | 0x7F800000u; /* overflow -> ±infinity */
    }
    exp += 2u;
    return sign | (exp << 23) | frac;
}




/* 
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
/* 
 * Multiply floating-point value by 64 (bit-level).
 * Follows IEEE-754 single-precision bit encoding.
 */
unsigned floatScale64(unsigned uf) {
    unsigned SIGN_MASK = 0x80000000u;
    unsigned EXP_MASK  = 0x7F800000u;
    unsigned FRAC_MASK = 0x007FFFFFu;
    unsigned INF_BITS  = 0x7F800000u;

    unsigned sign;
    unsigned exp;
    unsigned frac;
    unsigned shifted;
    unsigned extra_count;

    sign = uf & SIGN_MASK;
    exp  = (uf & EXP_MASK) >> 23;
    frac = uf & FRAC_MASK;

    if (exp == 0xFFu) return uf;
    if (exp == 0u && frac == 0u) return uf;

    if (exp == 0u) {
        shifted = frac << 6;
        if (shifted == 0u) return sign;
        if (shifted >= (1u << 23)) {
            extra_count = 0u;
            while (shifted >= (1u << 24)) {
                shifted = shifted >> 1;
                extra_count = extra_count + 1u;
            }
            /* now highest 1 is at bit 23; set exponent = 1 + extra_count */
            exp = 1u + extra_count;
            if (exp >= 0xFFu) return sign | INF_BITS;
            frac = shifted & FRAC_MASK;
        } else {
            exp = 0u;
            frac = shifted;
        }
    } else {
        unsigned new_exp = exp + 6u;
        if (new_exp >= 0xFFu) return sign | INF_BITS;
        exp = new_exp;
    }

    return sign | (exp << 23) | frac;
}




/* 
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u) {
    unsigned sign = 0;
    unsigned exp, frac, pos;
    unsigned mask, rest, half;

    if (u == 0)
        return 0;

    /* find highest bit pos (0–31) */
    pos = 31;
    while ((u & (1 << pos)) == 0)
        pos--;

    /* exponent = pos + bias (127) */
    exp = pos + 127;

    /* shift u left so that MSB is at bit 31 */
    /* then extract fraction bits from the next 23 bits */
    if (pos <= 23) {
        frac = (u << (23 - pos)) & 0x7FFFFF;
    } else {
        unsigned shift = pos - 23;
        unsigned shifted = u >> shift;
        frac = shifted & 0x7FFFFF;

        /* round-to-even */
        
        mask = (1 << shift) - 1;
        rest = u & mask;
        half = 1 << (shift - 1);

        if (rest > half || (rest == half && (frac & 1)))
            frac++;
        
        if (frac >> 23) { /* overflow rounding */
            exp++;
            frac &= 0x7FFFFF;
        }
    }

    return (sign) | (exp << 23) | frac;
}





