#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#define IN 0
#define OUT 1

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Please enter your file name" << endl;
    return 0;
  }
  
  string fileName = argv[1]; 
  cout << "File is " << fileName << endl;
  
  ifstream file(fileName);
  string line;
  int count = 0;
  int word = 0;
  int state = OUT;
  string sword;
  vector<string> sVector;
  while (getline(file, line)) {
    count++;
    //cout << line << endl;
    state = OUT;
    for(auto c : line) {
      if (c != ' ' || c != '\n' || c != '\t')
        sword +=c; 
      //cout << "char: " << c << endl;
      if (c == ' ' || c == '\n' || c == '\t') {
        state = OUT;
        if (sword != " ") {
          //cout << sword << endl;
          sVector.push_back(sword);
        }
        sword = "";
      } else if (state == OUT) {
        state = IN;
        word++;
      }
    }
    sVector.push_back(sword);
    //cout << sword << endl;
    sword = "";
  }

  cout << word << endl;
  cout << count << endl;
  for (auto s : sVector) {
    cout << s << endl;
  }
  
  return 0;
}
