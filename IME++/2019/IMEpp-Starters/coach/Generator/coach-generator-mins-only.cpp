#include "testlib.h"
#include <iostream>

using namespace std;

// use: n, x, d, maxsize

const int MAX_NUM = 1e9;
const int N_MAX = 15;
const int X_MAX = 1e9;
const int D_MAX = 1e9;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  int n = rnd.next(1, N_MAX);
  int x = rnd.next(1, X_MAX);
  int d = rnd.next(1, D_MAX);
  cout << n << " " << x << " " << d << endl;
  for(int i = 0; i < n; i++){
    if(i < n-1) cout << rnd.next(0, 0) << " ";
    else cout << rnd.next(0, 0) << endl;
  }
}
