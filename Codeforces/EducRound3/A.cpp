#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
vector<int> a;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int cnt = 0;
  for(int i = n-1; i >= 0; i--) {
    if(m <= 0) break;
    m -= a[i], cnt++;
  }
  cout << cnt << "\n";
} 
