#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  n *= 2, k *= 2;
  cout << max(5ll*((n+k-1)/k), 10ll) << "\n";
}
