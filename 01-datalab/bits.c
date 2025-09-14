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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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

/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
// 0 | 0 = 0
int bitOr(int x, int y) {
  return ~(~x & ~y);
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
  int iszero = !n;
  int flag = ~iszero + 1;
  return (~flag & (1 << 31) >> (n + (~1)+1));
}
/*
 * fullAdd - 4-bits add using bit-wise operations only.
 *   (0 <= x, y < 16) 
 *   Example: fullAdd(12, 7) = 3,
 *            fullAdd(7, 8) = 15,
 *   Legal ops: ~ | ^ & << >>
 *   Max ops: 30
 *   Rating: 2
 */
int fullAdd(int x, int y) {
  // 位运算作用在两个整数之间，实际上对单个位的操作是不会影响到其余位的，
  // 每个位取异或是加法之后的值，而取and是是否要进位，进位带到高位，
  // 所以把整体and，然后左移一位，异或，就是完成了加法操作，
  // 但是又有可能进位之后还要进位，最多操作四次（取整体and），那就暴力完成
  int base1 = x ^ y, up1 = (x & y) << 1;
  int base2 = base1 ^ up1, up2 = (base1 & up1) << 1;
  int base3 = base2 ^ up2, up3 = (base2 & up2) << 1;
  int base4 = base3 ^ up3; //up4 无所谓，反正只要最后4位
  int masklo4 = ~((1 << 31) >> 27);
  return base4 & masklo4;
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  // 把高位n字节移到低位n字节，需要右移字节数shift2lo=32-n，
  // 右移后需要消除高shift2lo符号位的影响，构造00..011，也就是11..100再取反,
  // 其中前面有shift2lo个1，对1<<31右移shift2lo-1位
  int shift2lo = 32 + (~n+1);
  int mask_for_shift = ~((1 << 31) >> (shift2lo + ~1+1));
  int hi2lo = (x >> shift2lo) & mask_for_shift;
  int lo2hi = x << n;
  return lo2hi | hi2lo;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  // 0 = 0, 1=1, 2=1, 3=2, 4=1, 5=2, 6=2, 7=3, 8=1, 9=2, 
  // 0x0000 0101  0x0101  0x00 0x0
  // 0x0000 0111  0x0111  0x10 0x1
  // 0x1001 0111  0x1110  0x01 0x1
  int x1 = (x >> 16) ^ x;
  int x2 = (x1 >> 8) ^ x1;
  int x3 = (x2 >> 4) ^ x2;
  int x4 = (x3 >> 2) ^ x3;
  int x5 = (x4 >> 1) ^ x4;
  int ans = x5 & 1;
  return ans;
}
/* 
 * palindrome - return 1 if x is palindrome in binary form,
 *   return 0 otherwise
 *   A number is palindrome if it is the same when reversed
 *   YOU MAY USE BIG CONST IN THIS PROBLEM, LIKE 0xFFFF0000
 *   YOU MAY USE BIG CONST IN THIS PROBLEM, LIKE 0xFFFF0000
 *   YOU MAY USE BIG CONST IN THIS PROBLEM, LIKE 0xFFFF0000
 *   Example: palindrome(0xff0000ff) = 1,
 *            palindrome(0xff00ff00) = 0
 *   Legal ops: ~ ! | ^ & << >> +
 *   Max ops: 40
 *   Rating: 4
 */
int palindrome(int x) {
  // 考虑把x反转然后异或，反转操作：
  // 不断二分并互换，第一步是归并排序的划分操作，每次划分都把相邻左右互换位置
  // 不要用掩码逐个提取，采用类似于4位加法的方式，整体取出
  int maskhi16 = 0xffff0000, masklo16 = 0xffff;
  int hi16lo = ((x & maskhi16) >> 16) & masklo16;
  int lo16hi = x << 16;
  int trans16 = lo16hi | hi16lo;

  // int mask81 = 0xff000000, mask82 = 0xff0000, mask83 = 0xff00, mask84 = 0xff;
  // int trans812 = (((x & mask81) >> 8) & mask82) | ((x & mask82) << 8);
  // int trans834 = (((x & mask83) >> 8) & mask84) | ((x & mask84) << 8);
  // int trans8 = trans812 | trans834;

  int maskhi8 = 0xff00ff00, masklo8 = 0x00ff00ff;
  int hi8lo = ((trans16 & maskhi8) >> 8) & masklo8;
  int lo8hi = (trans16 & masklo8) << 8;
  int trans8 = hi8lo | lo8hi;

  int maskhi4 = 0xf0f0f0f0, masklo4 = 0x0f0f0f0f;
  int hi4lo = ((trans8 & maskhi4) >> 4) & masklo4;
  int lo4hi = (trans8 & masklo4) << 4;
  int trans4 = hi4lo | lo4hi;

  int maskhi2 = 0xcccccccc, masklo2 = 0x33333333;
  int hi2lo = ((trans4 & maskhi2) >> 2) & masklo2;
  int lo2hi = (trans4 & masklo2) << 2;
  int trans2 = hi2lo | lo2hi;

  int maskhi1 = 0xaaaaaaaa, masklo1 = 0x55555555;
  int hi1lo = ((trans2 & maskhi1) >> 1) & masklo1;
  int lo1hi = (trans2 & masklo1) << 1;
  int trans1 = hi1lo | lo1hi;

  int iseq = !(trans1 ^ x);
  return iseq;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * oneMoreThan - return 1 if y is one more than x, and 0 otherwise
 *   Examples oneMoreThan(0, 1) = 1, oneMoreThan(-1, 1) = 0
 *   Legal ops: ~ & ! ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int oneMoreThan(int x, int y) {
  // 1 : y = x + 1, x+1+(~y+1)==0
  // 如果x正，y负，则必为0 -> diff=1 flag=0xffffffff

  int sx = (x >> 31) & 1;
  int sy = (y >> 31) & 1;
  int diff = (sx ^ 1) & (sx ^ sy);

  int flag = diff;
  int ans = x + 1 + (~y+1);
  return !(flag | ans);
  // return (!flag & !ans);
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
  int mul = (x << 1) + x;
  int bias = 3;
  int sign = (mul >> 31);
  return (mul + ((sign&bias))) >> 2;
  // return (mul<0 ? mul+3 : mul) >> 2;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  // x<y - x-y<0 - x+~y+1<0
  // x正y负 必为0； x负y正 必为1；即符号不同答案就是x的符号位
  int sx = (x >> 31);
  int sy = (y >> 31);
  int diff = sx ^ sy;
  int flag = diff;
  int ans = x + (~y+1);
  return ((~flag & (ans >> 31)) | (flag & sx)) & 1;
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x90000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
  // 当符号位发生变化时，发生溢出
  int tmin = 1 << 31;
  int tmax = ~tmin;

  int x2 = x + x;
  int sx0 = x >> 31;
  // int sx = sx0 & 1;
  int sx2 = x2 >> 31;
  int diff = sx0 ^ sx2;
  int flag = diff;

  int sat_val = (sx0 & tmin) | (~sx0 & tmax);
  return (~flag & x2) | (flag & sat_val);

}
/*
 * modThree - calculate x mod 3 without using %.
 *   Example: modThree(12) = 0,
 *            modThree(2147483647) = 1,
 *            modThree(-8) = -2,
 *   Legal ops: ~ ! | ^ & << >> +
 *   Max ops: 60
 *   Rating: 4
 */
int modThree(int x) {
  int is_3, should_eq_0, flag_for_tmin, flag_for_zero, reverse, for_zero, for_tmin;
  int sign = x >> 31;
  int y = (sign & (~x+1)) | (~sign & x);
  int tmin = 1 << 31;
  int is_tmin = !(x ^ tmin);
  int ans_minus3 = ~3+1;
  int ans_minus2 = ans_minus3 + 1;
  // if (x == (1<<31)) return -2;
  int mask = ~(tmin >> 15);
  y = (y >> 16) + (y & mask);
  y = (y >> 16) + (y & mask);
  y = (y >> 8) + (y & 0xff);
  y = (y >> 8) + (y & 0xff);
  y = (y >> 4) + (y & 0xf);
  y = (y >> 4) + (y & 0xf);
  y = (y >> 2) + (y & 0x3);
  y = (y >> 2) + (y & 0x3);

  // r = (r << 1) | ((y >> 1)&1);
  is_3 = !(y ^ 3);
  should_eq_0 = is_3;
  // return should_eq_0;
  // if (y==3 || y==-3) y=0;
  flag_for_tmin = ~is_tmin + 1;
  flag_for_zero = ~should_eq_0 + 1;
  
  reverse = (sign & (~y + 1)) | (~sign & y);
  for_zero = ((~flag_for_zero & reverse));
  for_tmin = (flag_for_tmin & ans_minus2) | (~flag_for_tmin & for_zero);
  return for_tmin;
  // return (flag_for_tmin & (~2+1)) | (~flag_for_tmin & 
  //        ((flag_for_zero & 0) | (~flag_for_zero & (sign & (~y+1)) | (~sign) & y)));
  // return (x>0?y:-y);

}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  int sign = uf & (1 << 31);
  int exp = (uf >> 23) & 0xff;
  int frac = uf & (0x7fffff);

  if (exp == 0xff) return uf;
  if (exp == 0) {
    frac = (frac >> 1) + ((frac & 3) == 3);
    return sign | frac;
  }
  if (exp == 1) {
    frac = ((frac >> 1) | (1 << 22)) + ((frac & 3) == 3);
    return sign | frac;
  }
  return sign | (exp - 1) << 23 | frac;
  // if (exp <= 1) {
  //   // 把exp=1的情况归纳到非规格，直接向右移位，把隐含的1移到尾数中，相当于除以2，而指数部分是不变的
  //   // 涉及到舍入的问题，向偶数，如果最后两位是11需要向上舍入，如果是01需要向下舍入
  //   if ((frac & 3) == 3) {
  //     uf = (no_sign >> 1) + 1;
  //   } else {
  //     uf = (no_sign >> 1);
  //   }
  //   return uf | sign;
  // }
  // exp--;
  // return sign | (exp << 23) | frac;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  // 特殊判断，如果x=0、tmin直接返回，因为找不到除了符号位之外的1
  int tmin = 1 << 31;
  int sign, first1 = 0, frac, frac_mask, exp, out, idx;
  if (x == 0) { return 0; }
  if (x == tmin) { return (0xcf << 24); }

  sign = tmin & x;
  
  /*
   * // 把符号位置为0，然后从左往右找到一个1的位置
   * // x &= ~tmin;
   * 这里应该是x取相反数，不是简单的修改符号位
   */
  if (sign >> 31) { x = -x; }
  for (idx = 31; idx >= 0; idx--) {
    if ((x >> idx) & 1) {
      first1 = idx;
      break;
    }
  }
  // 现在已有的是2^(first1)，bias=127，则可以求E
  exp = 127 + first1;
  /*
   * 这里考虑的方式是，把frac的23位直接放到低23位上，这是最终目标；
   * 方式是，首先把找到的first1左移到最高位，隐含的1在最高位，然后再右移8位，此时1在第24位（1-based）；
   * 那么就可以用掩码0x7fffff取出低23位。
   * 但是考虑到如果原来的frac长于23位，会涉及到进位的问题，
   * 那就把x要右移出去的8位提取出来，如果大于0x80，或者恰好是0x80且已经取出来的23位的frac的最低位是1，都需要向偶数舍入；
   * 这里舍入可能进位，导致frac的第24位变成1，如果这样，重新用掩码取出来frac，并把exp加1；
   * 原因是相当于frac又右移了一位，除以2，需要exp+1来弥补
   */
  x <<= (31 - first1);
  frac_mask = 0x7fffff;
  frac = (x >> 8) & frac_mask;

  out = x & 0xff;
  if (out > 0x80 || (out == 0x80 && frac & 1)) { frac += 1; }

  if (frac >> 23) {
    frac = frac & frac_mask;
    exp++;
  }

  return sign | (exp << 23) | frac;
}
/* 
 * float64_f2i - Return bit-level equivalent of expression (int) f
 *   for 64 bit floating point argument f.
 *   Argument is passed as two unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   double-precision floating point value.
 *   Notice: uf1 contains the lower part of the f64 f
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 20
 *   Rating: 4
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
  // 1 11 52
  int tmin = 1 << 31;
  int sign = uf2 >> 31;
  int exp_mask = 0x7ff;
  int exp = (uf2 >> 20) & exp_mask;
  int E = exp - 1023;
  int deltaE = 31 - E;
  int frac = ((uf2 & 0xfffff) << 11/*留了最高位给隐含的1*/) | ((uf1 >> 21) & 0x7ff) | tmin;

  if (E < 0) return 0;
  if (E >= 31) return tmin;
  frac = frac >> (deltaE/*右移31补偿，再左移E做乘法*/) & ~(tmin >> deltaE << 1/*高位右移的1去掉*/);
  if (sign) frac = -frac;
  return frac;
}
/* 
 * float_pwr2 - Return bit-level equivalent of the expression 2.0^x
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
unsigned float_pwr2(int x) {
  /*
   * 单精度，
   * 最小非规格：2^-23 * 2^(1-127) = 2^-149
   * 最大非规格：（1-e）* 2^(1-127) = 2^-126
   * 也即只要x<-149，就是0；-149<=x<-126，就是非规格，直接左移x-149位
   * 
   * 最小规格：(1+2^-23) * 2^(1-127) = 2^-126+2^-149
   * 最大规格：(2-e) * 2^(254-127) = (2-e) * 2^127
   * 只要x>=128，就是inf，0x7f800000
   * 我们本身就知道规格化的指数部分的范围，-126 ~ 127
   * 
   * 
   */
  if (x < -149) {
    return 0;
  } else
  if (x >= -149 && x <= -127) {
    return (1 << (x + 149));
  } else
  if (-126 <= x && x <= 127) {
    return (x + 127) << 23;
  } else
  // if (x >= 128) 
  {
    return 0x7f800000;
  }
  
}

