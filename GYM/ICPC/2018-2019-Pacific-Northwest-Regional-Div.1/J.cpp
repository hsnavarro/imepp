#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

int n, s, mx, a;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> s;
  while(n--) cin >> a, mx = max(mx, a);
  cout << (s*mx+999)/1000 << "\n";
}
