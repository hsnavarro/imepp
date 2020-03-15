#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 5;

int n;
pair<int, int> a[N];
set<pair<int, int>> s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i].st >> a[i].nd;
  if(n & 1) return cout << "NO\n", 0;
  for(int i = 0; i+n/2 < n; i++) {
    s.insert({a[i].st + a[i+n/2].st, a[i].nd + a[i+n/2].nd});
  }
  cout << (s.size() == 1 ? "YES\n" : "NO\n");
}
