#include<bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(0, 1000000, "N");
  inf.readEoln();

  int len = 0;
  for(int i = 0; i < n; i++){
    string s = inf.readString();
    for(auto c : s) ensuref(c >= 'a' and c <= 'z', "Must be lower case english letters");
    len += s.size();
    inf.readEoln();
  }

  ensuref(len <= 1e6, "The sum of all words should be smaller than 1e6");
  inf.readEof();
}
