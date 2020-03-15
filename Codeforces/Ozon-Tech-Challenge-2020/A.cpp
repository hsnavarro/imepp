#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int t, n, x;
vector<int> a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    a.resize(n), b.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(auto x : a) cout << x << " ";
    cout << "\n";
    for(auto x : b) cout << x << " ";
    cout << "\n";
  }
}
