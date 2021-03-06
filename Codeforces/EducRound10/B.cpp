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

int n, a;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    v.pb(a);
  }
  sort(v.begin(), v.end());
  vector<int> aux;
  for(int i = 0; i < n; i++) {
    if(i > n - 1 - i) break;
    aux.pb(v[i]);
    if(i >= n - 1 - i) break;
    aux.pb(v[n - 1 - i]);
  }
  for(auto x : aux) cout << x << " ";
  cout << "\n";
} 

