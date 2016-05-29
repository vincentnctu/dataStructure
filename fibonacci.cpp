#include <iostream>

using namespace std;

int fibRecursive(int n) {
  if (n == 0)
    return 0;
  
  if (n == 1 || n == 2) 
    return 1;

  return fibRecursive(n - 1) + fibRecursive(n - 2);

} 

int fibNonRecursive(int n) {
  if (n == 0)
    return 0;
  
  if (n == 1 || n == 2) 
    return 1;
  
  int f[n];
  f[0] = 0;
  f[1] = 1;

  for (int i = 2; i < n+1; i++) {
    f[i] = f[i-1] + f[i-2];
  }
  return f[n];
}


int main(int argc, char *argv[]) {
  int n;
  cin >> n;   

  for (int i = 0; i < n; i++) {
    cout << fibRecursive(i) << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    cout << fibNonRecursive(i) << " ";
  }
  cout << endl;
  return 0;
}
