#include <iostream>

using namespace std;

#define Max 5
#define ArraySize(array, type) sizeof(array)/sizeof(type)

int A[Max] = {3, 8, 9, 7, 6};

void arrayRotation(const int *a, const int size, int *b, int k) {
  int index;
  for (int i = 0; i < size; i++) {
    index = i - k%size;
    if (index < 0) {
      index += size;
    }
    b[i] = a[index];
  }
}

int main(int argc, char *argv[]) {
  cout << "Array length = " << ArraySize(A, int)  << endl;
  unsigned size = ArraySize(A, int);
  int outArray[size];

  arrayRotation(A, size, outArray, 2);
  for(auto i:outArray) {
    cout << i << " ";
  }
  cout << endl;
}
