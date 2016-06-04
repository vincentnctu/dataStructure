#include <stdio.h>

int solution(int N) {
    // write your code in C99 (gcc 4.8.2)
    int k;
    int i;
    int start = 0;
    int start2 = 0;
    int max = 0;
    int count = 0;

    for (i = 31; i >= 0 ; i--) {
      k = N >> i;
      if (k & 1) {
          printf("1");
          start = 1;
          if (start2 == 1) {
              if (max < count) { 
                  max = count;
              }
              count = 0;
              start2 = 0;
          }
      } else {
          printf("0");
          if (start == 1) {
             start2 = 1;
             count++;
          }
      }
    }
    if (start2 == 1) {
        if (max < count) {
            max = count;
        }
    }
    return max;
}

int mystrcmp(char *src, char *dest) {

  while (*src != '\0' && (*src++ == *dest++));
  return *src - *dest;
}

int sum(int n){
  if (n == 0 || n == 1)
    return 0;

  if (n == 2) 
    return 2;

  return sum(n-1) + n*(n-1);
}

int main(int argc, char *argv[]) {
  printf("max gap is %d\n", solution(51712));
}
