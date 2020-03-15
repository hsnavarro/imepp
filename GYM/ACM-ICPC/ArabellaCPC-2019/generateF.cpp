#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e3;
const int N = 1000;

int main() {
  int n = rand()%(N) + 1;
  int p = rand()%n + 1;
  cout << n << " " << p << endl;
  for(int i = 0; i < n-1; i++) cout << rand()%MOD + 1 << " ";
  cout << endl;
  for(int i = 0; i < n-1; i++) cout << rand()%n + 1 << " ";
  cout << endl;
}
