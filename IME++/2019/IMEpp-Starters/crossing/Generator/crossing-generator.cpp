#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  int len = atoi(argv[1]);
  cout << rnd.next("[a-z]{1, %d}", len) << " " << rnd.next("[a-z]{1, %d}", len) << endl;
}
