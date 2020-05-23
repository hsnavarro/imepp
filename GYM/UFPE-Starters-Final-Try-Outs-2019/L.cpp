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
const int N = 1e4+1, T = 3e5 + 5, M = 2e5 + 5;
 
ll n, q;
ll v[N], wh[N], ex[N];

int idx;
ll dp[2][N], ans[M];

vector<int> add[T];
vector<ll> times;
// w, idx
vector<pair<ll, int>> qsn[T];
vector<pair<ll, ll>> qs;
 
void knap(int id) {
  idx++;
  ll val = v[id];
  ll wt = wh[id];
  for(int w = 0; w < N; w++) {
      if(w - wt >= 0) dp[idx%2][w] = 
        max(dp[(idx-1)%2][w], dp[(idx-1)%2][w - wt] + val);
      else dp[idx%2][w] = dp[(idx-1)%2][w];
  }
} 
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> v[i] >> wh[i] >> ex[i];
    times.pb(ex[i]);
  }
  ll tm, wlvl;
  while(q--) {
    cin >> tm >> wlvl;
    qs.push_back({tm, wlvl});
    times.pb(tm);
  }
 
  sort(times.begin(), times.end());
  times.resize(unique(times.begin(), times.end()) - times.begin());
  
  for(int i = 1; i <= n; i++) {
    int t = lower_bound(times.begin(), times.end(), ex[i]) - times.begin();
    add[t].push_back(i);
  }

  for(int i = 0; i < qs.size(); i++) {
    int realtm = 
      lower_bound(times.begin(), times.end(), qs[i].st) - times.begin();
    qsn[realtm].push_back({qs[i].nd, i});
  }
 
 
  for(int i = times.size() - 1; i >= 0; i--) {
    for(auto x : qsn[i]) ans[x.nd] = dp[idx%2][x.st];
    for(auto x : add[i]) knap(x);
  }
  
  for(int i = 0; i < qs.size(); i++) cout << ans[i] << "\n";
  
}
 
