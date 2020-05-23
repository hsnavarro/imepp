#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 1e6+5;

int t, n, k;
string s;
int ps[N];

int sum(int l, int r) {
  l = max(l, 0);
  int ans = ps[r];
  if(l-1) ans -= ps[l-1];
  return ans;
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> k;
    cin >> s;
    ps[0] = (s[0] == '1');
    for(int i = 1; i < n; i++) ps[i] = (s[i] == '1') + ps[i-1];

    int mn = (int) 1e9;
    int cost = 0;
    for(int i = 0; i <= k; i++) {
      cost = 0;
      int ptr = i;
      while(ptr < n) {
        int value = sum(ptr-k, ptr);
        if(s[ptr] == '0') cost += value + 1;
        else cost += value-1;
        ptr += k;
      }
      mn = min(mn, cost);
    }
    cout << mn << "\n";
  }
}

