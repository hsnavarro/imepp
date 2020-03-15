#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MIN_N = 1;
const int MIN_Q = 1;

const int MAX_N = 20;
const int MAX_Q = 20;

const string pattern = "[A-Z][a-z]{1,9}";

int n, cnt;

map<int, string> name;
unordered_set<string> names;

void gen(int type) {
  int l = rnd.next(1, n);
  int r = rnd.next(1, n);
  while(l == r) l = rnd.next(1, n), r = rnd.next(1, n);
  cout << type << " " << name[l] << " " << name[r] << "\n";
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  n = rnd.next(MIN_N, MAX_N);
  int q = rnd.next(MIN_Q, MAX_Q);
  cout << n << " " << q << "\n";

  while(names.size() != n){
    string name_i = rnd.next(pattern);
    names.insert(name_i);
  }
  int index = 1;
  for(auto x : names){
    name[index] = x;
    cout << x << "\n";
    index++;
  }

  for (int i = 1; i <= q; i++) {
    if (i == q and !cnt) {
      gen(2);
      break;
    }

    int t_i = rnd.next(1, 2);
    if(t_i == 2) cnt++;
    gen(t_i);
  }

  return 0;
}

