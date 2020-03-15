#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MIN_N = 1;
const int MIN_Q = 1;

const int MAX_N = 1e2;
const int MAX_Q = 1e2;

int n, cnt;

void genType1() {
  int l = rnd.next(1, n);
  int r = rnd.next(1, n);
  if(l > r) swap(l, r);
  printf("1 %d %d\n", l, r);
}

void genType2() {
  int i = rnd.next(1, n);
  int value = rnd.next(0, 10);
  printf("2 %d %d\n", i, value);
}


int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  n = rnd.next(MIN_N, MAX_N);
  int q = rnd.next(MIN_Q, MAX_Q);
  printf("%d %d\n", n, q);

  for (int i = 1; i <= n; i++) {
    int grade_i = rnd.next(0, 10);
    printf("%d%c", grade_i, " \n"[i==n]);
  }

  for (int i = 1; i <= q; i++) {
    if (i == q and !cnt) {
      genType1();
      break;
    }

    int t_i = rnd.next(1, 2);
    if (t_i == 1) genType1(), cnt++;
    else genType2();
  }

  return 0;
}

