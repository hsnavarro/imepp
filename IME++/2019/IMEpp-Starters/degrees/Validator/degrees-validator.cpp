#include <bits/stdc++.h>
#include "testlib.h"

const int MAX_N = 1e3;
const int MAX_M = 1e3;

using namespace std;

int edges[MAX_N + 1][MAX_N + 1];

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(2, MAX_N, "n");
  inf.readSpace();
  int m = inf.readInt(0, (n*(n-1))/2, "m");
  inf.readEoln();

  for (int i = 1; i <= m; i++) {
    int a = inf.readInt(1, n, "a");
    inf.readSpace();
    int b = inf.readInt(1, n, "b");
    inf.readEoln();

    ensure(a != b);
    ensuref(!edges[a][b], "Routes %d and %d are equal", edges[a][b], i);
    ensuref(!edges[b][a], "Routes %d and %d are equal", edges[b][a], i);
    edges[a][b] = i;
    edges[b][a] = i;
  }
  inf.readEof();
}

