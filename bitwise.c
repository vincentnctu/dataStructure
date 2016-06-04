#include <stdio.h>

// Get n bits from postion p of x.
int 
getbits(int x, int p, int n) {
  return (x >> (p + 1 -n)) & ~(~0<<n);
}

// Returns x with the n bits that begin at position p
// set to the rightmost n bits of y, leaving the other bits unchanged.
//
// bits 7654 3210
// x  = 1111 1111
// y  = 1110 1011
// If we would like to set 3 bits that begin at postion 4 to the rightmost 
// 3 bits of y, then we should
// x & 1110 0011 | y & 0001 1100
int
setbits(int x, int p, int n, int y) {
  return (x & ~(~(~0 << n) << (p + 1 -n))) | (y & (~(~0 << n) << (p + 1 -n)));
}

// Return x with the n bits that begin at postion p inverted.
int invert(x, p, n) {
  return setbits(x, p, n, ~x);
}

// Return the value of the integer x rotated to the right by n bit postions.
int
rightrot(unsigned x, int n) {
  unsigned v = (unsigned) (~0);
  int length = 0;
  unsigned rbits;

  for (length = 1; (v = v >> 1) > 0; length++) {
    ;
  }

  rbits = x << (length - n);
  x = x >> n;
  return rbits | x;
}

// Return the value of the integer x rotated to the left by n bit postions.
int
leftrot(unsigned x, int n) {
  unsigned v = (unsigned) (~0);
  int length = 0;
  unsigned lbits;

  for (length = 1; (v = v >> 1) > 0; length++) {
    ;
  }

  lbits = x >> (length - n);
  x = x << n;
  return lbits | x;
}

int bitcounts(unsigned n) {
  int i = 0;
  for ( ; n != 0 ; n = n >> 1) {
    if (n & 01)
      i++;
  }
  return i;
}

int 
main(int argc, char *argv[]) {
  printf("%x\n", getbits(255, 4, 3));
  printf("%x\n", setbits(255, 4, 3, 0));
  printf("%x\n", invert(255, 7, 4));
  printf("%x\n", rightrot(0xcb, 3));
  printf("%x\n", leftrot(0xcb, 3));
  printf("%d\n", bitcounts(10));
  return 0;
}
