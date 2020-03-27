#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

const int N = 1e3 + 5;

int n, sum[N], a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    sum[a]++, sum[b+1]--;
  }
  for(int i = 1; i <= n; i++) {
    sum[i] += sum[i-1];
  }

  int ans = -1;
  for(int j = 1; j <= n; j++)
    if(sum[j] == j) ans = j;

  cout << ans << "\n";
}
