#include "testlib.h"
#include <iostream>

using namespace std;

int idx;

string auxiliar (int n){
  if(n == 0) return "";
  string aux = auxiliar(n-1);
  idx++;
  string ans = aux + char(int(idx % 26 + 'a')) + aux;
  if(ans.size() > 1000) return aux;
  return ans;
}

string createTest(int n){
  idx = -1;
  return auxiliar(n);
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  int iter = atoi(argv[1]);
  cout << createTest(rnd.next(1, iter)) << " " << createTest(rnd.next(1, iter)) << endl;
}
