#include <bits/stdc++.h>
using namespace std;

int x, b;

int main() {
  cin >> x;
  do {
    cout << b << "\n";
    assert((b & x) == b);
  } while(b = (b - x) & x);

}
