#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "bits.h"

test_rec test_set[] = {
/* Copyright (C) 1991-2024 Free Software Foundation, Inc.
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
   <https://www.gnu.org/licenses/>.  */
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
// 2023
/*

#include "bitXnor.c" // 1

#include "bitConditional.c" // 1

#include "byteSwap.c" // 2

#include "logicalShift.c" // 3

#include "cleanConsecutivel.c" // 

#include "leftBitCount.c"



#include "counter1To5.c"

#include "sameSign.c"

#include "satMul3.c"

#include "isGreater.c"

#include "subOK.c"

#include "trueFiveEighths.c"



#include "float_half.c"

#include "float_i2f.c"

#include "float64_f2i.c"

#include "float_negpwr2.c"

*/
// 2024
/*

#include "bitAnd.c" // 1 

#include "bitConditional.c" // 1

#include "implication.c" // 2

#include "rotateRight.c" // 3

#include "bang.c" // 4

#include "countTrailingZero.c" // 4



#include "divpwr2.c" // 2

#include "sameSign.c" // 2

#include "multFiveEighths.c" // 3

#include "satMul3.c" // 3

#include "isLessOrEqual.c" // 3

#include "ilog2.c" // 4



#include "float_twice.c"   // 4 

#include "float_i2f.c"     // 4

#include "float64_f2i.c"     // 4

#include "float_negpwr2.c"    // 4

*/
// 2025
 {"bitOr", (funct_t) bitOr, (funct_t) test_bitOr, 2, "& ~", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"upperBits", (funct_t) upperBits, (funct_t) test_upperBits, 1, "! ~ & ^ | + << >>", 10, 1,
  {{0, 32},{TMin,TMax},{TMin,TMax}}},
 {"fullAdd", (funct_t) fullAdd, (funct_t) test_fullAdd, 2,
    "~ & ^ | << >>", 30, 2,
  {{0, 15}, {0, 15}, {TMin, TMax}}},
 {"rotateLeft", (funct_t) rotateLeft, (funct_t) test_rotateLeft,
   2, "! ~ & ^ | + << >>", 25, 3,
  {{TMin, TMax},{0,31},{TMin,TMax}}},
 {"bitParity", (funct_t) bitParity, (funct_t) test_bitParity, 1, "! ~ & ^ | + << >>", 20, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"palindrome", (funct_t) palindrome, (funct_t) test_palindrome, 1,
    "~ ! | ^ & << >> +", 40, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"negate", (funct_t) negate, (funct_t) test_negate, 1,
    "! ~ & ^ | + << >>", 5, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"oneMoreThan", (funct_t) oneMoreThan, (funct_t) test_oneMoreThan, 2,
    "~ & ! ^ | + << >>", 15, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"ezThreeFourths", (funct_t) ezThreeFourths, (funct_t) test_ezThreeFourths, 1,
    "! ~ & ^ | + << >>", 12, 3,
  {{TMin,TMax},{TMin,TMax},{TMin,TMax}}},
 {"isLess", (funct_t) isLess, (funct_t) test_isLess, 2,
    "! ~ & ^ | + << >>", 24, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"satMul2", (funct_t) satMul2, (funct_t) test_satMul2, 1,
    "~ & ^ | + << >>", 20, 3,
  {{TMin,TMax},{TMin,TMax},{TMin,TMax}}},
 {"modThree", (funct_t) modThree, (funct_t) test_modThree, 1,
    "~ ! | ^ & << >> +", 60, 4,
  {{TMin, TMax}, {TMin, TMax}, {TMin, TMax}}},
 {"float_half", (funct_t) float_half, (funct_t) test_float_half, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
 {"float_i2f", (funct_t) float_i2f, (funct_t) test_float_i2f, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
 {"float64_f2i", (funct_t) float64_f2i, (funct_t) test_float64_f2i, 2,
    "$", 20, 4,
     {{1, 1},{1,1},{1,1}}},
 {"float_pwr2", (funct_t) float_pwr2, (funct_t) test_float_pwr2, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
  {"", NULL, NULL, 0, "", 0, 0,
   {{0, 0},{0,0},{0,0}}}
};
