#include <iostream>

using namespace std;

// 64 bits decimal number to binary form
string decimalToBinary(unsigned long n) {
  unsigned long k;
  string binary;
  bool first = false;

  for (int i = 63; i >= 0 ; i--) {
    k = n >> i;
    if (k&1) {
      first = true;
      binary += "1";
   
    } else {
      if (first) {
        binary += "0";
      }
    }
  }
  cout << endl;
  return binary;
}

int main(int argc, char *argv[]) {
  unsigned long n;
  string result;
  
  while (1) {
    cin >> n;
    result = decimalToBinary(n);
    cout << result << endl;
    int count = 0;
    bool start = false;
    int max = 0;
    for (char c:result) {
      cout << c << endl;
      if (c == '0') {
        start = true;
        count ++;
      } else {
        if (start) {
          start = false;
          if (max < count) {
            max = count;
            count = 0;
          }
        }
      }
    }
    if (start) {
      if (max < count) {
        max = count;
      }
    }
    cout << "Max gap is " << max << endl; 
  }

  return 0;
}
