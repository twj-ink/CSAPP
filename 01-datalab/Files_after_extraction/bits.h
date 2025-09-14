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
int bitOr(int, int);
int test_bitOr(int, int);
int upperBits(int);
int test_upperBits(int);
int fullAdd(int, int);
int test_fullAdd(int, int);
int rotateLeft(int, int);
int test_rotateLeft(int, int);
int bitParity(int);
int test_bitParity(int);
int palindrome(int);
int test_palindrome(int);
int negate(int);
int test_negate(int);
int oneMoreThan(int, int);
int test_oneMoreThan(int, int);
int ezThreeFourths(int);
int test_ezThreeFourths(int);
int isLess(int, int);
int test_isLess(int, int);
int satMul2(int);
int test_satMul2(int);
int modThree(int);
int test_modThree(int);
unsigned float_half(unsigned);
unsigned test_float_half(unsigned);
unsigned float_i2f(int);
unsigned test_float_i2f(int);
int float64_f2i(unsigned, unsigned);
int test_float64_f2i(unsigned, unsigned);
unsigned float_pwr2(int);
unsigned test_float_pwr2(int);
