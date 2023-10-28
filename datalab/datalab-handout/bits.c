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
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
// done
int bitXor(int x, int y) {
    // x^y = (~(~x&~y))&(~(x&y))
    return (~(~x & ~y)) & (~(x & y));
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
// done
int tmin(void) {
    return 1 << 31;
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
// done
int isTmax(int x) {
    // the number is 0111..111, so uh...yeah following code is right.
    return (!((~x) ^ (x + 1))) & (!!(x + 1));
    // return (!((~2147483647) ^ (2147483647 + 1))) & (!(2147483647 + 2147483647 + 2));
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
// done
int allOddBits(int x) {
    int AAAAAAAA = 0xAA + (0xAA << 8) + (0xAA << 16) + (0xAA << 24);
    return !(~(~(x & AAAAAAAA) + AAAAAAAA));
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
// done.so easy..
int negate(int x) {
    return ~x + 1;
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
// done
// Get the differences between x and 48 / 57, then judge if the differences are positive/negative.Should notice that x could be 48 and 57.
int isAsciiDigit(int x) {
    int minusX = ~x + 1;
    int negative = 1 << 31;
    return !((~(48 + minusX) + 1) & negative) & !((~(57 + minusX) & negative) ^ negative);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
// done
int conditional(int x, int y, int z) {
    int a = ~(!x) + 1;  // x != 0 -> a = 00000000 ; x == 0 -> a = ffffffff
    return ((~a) & y) + (a & z);
    // return ~a;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
// done
int isLessOrEqual(int x, int y) {
    // if calculate x-y, when in x <= y case the result would be negative or positive which is difficult to handle, so calculate y-x instead.
    int minusX = ~x + 1;
    int negative = 1 << 31;
    int xP = !(x & negative);
    int yP = !(y & negative);
    int xPyN = xP & !yP;
    int xNyP = !xP & yP;
    return (!((y + minusX) >> 31) & !xPyN) | xNyP | !(x ^ y);
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
// done
int logicalNeg(int x) {
    /*
        Notice that only 10..00 and 0..0 have the property of having complement same as itself,
        which means any other number and its complement must include one and only one negative number(the very first bit is 1).
        and the difference between 10.00 and 0..0 also lies on the first number.
    */
    int complement = ~x + 1;
    return ~(((complement >> 31) & 1) | ((x >> 31) & 1)) + 2;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
// done
int howManyBits(int x) {
    /*
        The position of the first '1' determines final output.
        So use dichotomy to find it.
    */
    int X = x ^ (x >> 31);
    int AllF = ~0;
    int flag = 16;
    int left = (X >> flag) & (0xff + (0xff << 8));
    // All following ((!left) + AllF) == 0 when the current left side of the current flag doesn't contain '1'
    flag = flag + (8 & ((!left) + AllF)) + ((~8 + 1) & (~((!left) + AllF)));
    left = (X >> flag) & 0xff;
    flag = flag + (4 & ((!left) + AllF)) + ((~4 + 1) & (~((!left) + AllF)));
    left = (X >> flag) & 0xf;
    flag = flag + (2 & ((!left) + AllF)) + ((~2 + 1) & (~((!left) + AllF)));
    left = (X >> flag) & 0x3;
    flag = flag + (1 & ((!left) + AllF)) + ((~1 + 1) & (~((!left) + AllF)));
    left = (X >> flag) & 0x1;
    // In final round you only need to judge the flag itself and flag-1
    flag = flag + ((~1 + 1) & (~((!left) + AllF)));
    // Considering 2 facts that the index is 1 less than output and Sign bit counts, flag should plus 2.
    // last 2 terms are added specifically to treat 0 and -1 cases, whose output are 1.
    return flag + 2 + (~(!(x)) + 1) + (~(!(~x)) + 1);
}
// float
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
    unsigned signPos = uf & 0x80000000;
    unsigned expPos = uf & 0x7f800000;
    unsigned frac = uf & 0x007fffff;
    unsigned exp = expPos >> 23;
    if (exp == 255 || (exp == 0 && frac == 0)) {
        return uf;
    }
    if (exp == 0) {
        /*
            Genius engineers set up the pattern of float number to simplify the process of
            turning denormalized float number to be normalized.
            Thus simply make Frac shifts left for 1 bit is fine to calculate 2*f.
        */
        frac = (frac << 1);
        return signPos | expPos | frac;
    }
    // exp != 0
    exp += 1;
    expPos = exp << 23;
    return signPos | expPos | frac;
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
int floatFloat2Int(unsigned uf) {
    unsigned signPos = uf & 0x80000000;
    unsigned expPos = uf & 0x7f800000;
    unsigned exp = expPos >> 23;
    int i = exp - 127;
    // get the integer part
    unsigned frac = (uf & 0x007fffff) >> (23 - i - 1);
    // in case the frac should plus 1 because of rounding rule
    int judge = frac & 1;
    // the implied leading 1
    int one = 1 << i;

    if (exp >= 158) {
        return 0x80000000;
    }
    if (exp <= 126) {
        return 0;
    }
    // 127 - 157 (actual_exp == 0-30)
    frac = (frac >> 1) | one;
    if (judge)
        frac += 1;
    if (signPos == 0) {
        return frac;
    }
    return ~frac + 1;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floa3ting-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   +
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    unsigned sign = 0x00000000;
    unsigned frac = 0x00000000;
    unsigned exp = (x + 127) << 23;
    if (x <= -150) {
        return 0;
    }
    if (x >= 128) {
        return 0xFF << 23;
    }
    // -126 ~ 127 : normalized float
    if (x >= -126) {
        return sign | exp | frac;
    }
    // -149~ -127 : denormalized float
    else {
        frac = 1 << (23 + x + 126);
        exp = 0x00000000;
        return sign | exp | frac;
    }
}
