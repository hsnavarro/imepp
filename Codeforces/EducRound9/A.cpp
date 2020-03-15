#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

string s;
ll n, p, cost;
vector<string> v;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> p;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  ll x = 0;
  for(int i = n-1; i >= 0; i--) {
    if(v[i] == "halfplus") x = 2*x+1;
    else x = 2*x;
  }

  db(x);
  for(int i = 0; i < n; i++) {
    if(v[i] == "halfplus") cost += (x*p)/2, x -= (x+1)/2;
    else cost += (x/2)*p, x -= (x/2);
  }
  cout << cost << "\n";
}

