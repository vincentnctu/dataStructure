#include <iostream>
#include <math.h>

using namespace std;

void divisor(int n) {
  if (n < 0) {
    cout << "Invalid number" << endl;
    return;
  }

  if (n == 0) {
    cout << "zero" << endl;
    return;
  }
  
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (n%i == 0) {
      count++;
      cout << i << " ";
    }
  }
  cout << endl;
}

int bcd(int a, int b) {
  if (!(a != 0 && b != 0)) {
    cout << "Invalid input" << endl;
    return -1;
  }

  int c;
  c = b;
  while (!(a%c == 0 && b%c == 0)) c--;
  return c;
}

int bcd2(int a, int b) {
  if (b) {
    while ((a %= b) && (b %= a));
  }
  return a + b;
}

int lcm(int a, int b) {
  return a*b/bcd2(a, b);
}

int sum(int n) {
  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return 1;
  }

  return sum(n-1) + n;
}

void prime(int n) {
  int got;

  for (int i = 1; i < n; i++) {
    got = 1;
    int v = (int)sqrt((double)i);
    for (int j = 2; j < i; j++) {
      if (i%j == 0) {
        got = 0; 
      }
    }
    if (got) {
      cout << i << " "; 
    }
  }
  cout << endl;
}

//a*b = lcm(a, b) * gcd(a, b)
int main(int argc, char *argv[]) {
  for (int i = 0; i <= 10; i++) {
    divisor(i);
  }
  int a=2, b=7; 
  cout << "bcd = " << bcd(a, b) << " lcm = " << lcm(a, b) << endl;
  cout << "Sum = " << sum(100) << endl;
  prime(10);
  return 0;
}
