#include <iostream>

using namespace std;

int array[] = {1, 3, 2, 5, 4, 7, 6, 9, 8};

#define arraySize(a, t) sizeof(a)/sizeof(t)

enum ORDER {
  INC = 0, 
  DEC = 1
};

void selSort(int *in, int n, ORDER order) {
  int tmp;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1 ; j < n; j++) {
      if (order == DEC) {
        if (in[i] < in[j]) {
          tmp = in[i];
          in[i] = in[j];
          in[j] = tmp;
        }
      } else {
        if (in[i] > in[j]) {
          tmp = in[i];
          in[i] = in[j];
          in[j] = tmp;
        }
      }
    }
  }
}

// index of array we found.
int binarySearch(int *in, int n, int key) {
  int start, end, mid;
  start = 0;
  end = n - 1;

  while (start <= end) {
    mid = (end-start)/2 + start;
    if (in[mid] == key) {
      return mid;
    } else if (in[mid] > key) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  int length = arraySize(array, int);
  int out[length];

  for (int i = 0; i < length; i++) {
    cout << array[i] << " "; 
  }
  cout << endl;

  selSort(array, length, INC);

  for (int i = 0; i < length; i++) {
    cout << array[i] << " "; 
  }
  cout << endl;
  cout << binarySearch(array, length, 7) << endl;
  return 0;
}
