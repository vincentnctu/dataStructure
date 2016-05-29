#include <iostream>

using namespace std;

bool findNonRepeatedChar(char *str, int length, char *find) {
  int count[256];
  char *ptr = str;
  memset(count, 0, 256);

  for (int i = 0; i < length; i++) {
    count[str[i]]++;
  }

  for (int i = 0; i < length; i++) {
    if (count[str[i]] == 1) {
      *find = str[i];
      return true;
    }
  }
  
  return false; 
}

void strReverse(char *s) {
  int i,j;
  char tmp;
  for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

int main(int argc, char *argv[]) {
  char str[] = "aabcddecbf";
  char find;
 
  if (findNonRepeatedChar(str, strlen(str), &find)) {
    cout << "Find the character: " << find << endl;
  } else {
    cout << "Can't find the character in " << str << endl; 
  }

  strReverse(str);
  cout << str << endl;

  return 0;
}
