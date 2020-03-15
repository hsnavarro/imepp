#include <bits/stdc++.h>
using namespace std;

#define int long long

unsigned int n;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  cout << (1ll << (__builtin_popcountll(n))) << "\n";
}
