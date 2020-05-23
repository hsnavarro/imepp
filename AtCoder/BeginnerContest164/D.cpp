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
const int N = 2e5+5;

string txt;
int dp[N];
int cnt[2020];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> txt;

  int mult = 1;
  for(int i = txt.size(); i >= 1; i--) {
    dp[i] = (dp[i+1] + (mult*(txt[i-1] - '0')) % 2019 ) % 2019;
    //db(i _ dp[i]);
    mult = ( mult*10 ) % 2019;
  }

  int ans = 0;
  for(int i = 1; i <= txt.size(); i++) {
    if(!dp[i]) ans++;
    ans += cnt[dp[i]];
    cnt[dp[i]]++;
  }
  
  cout << ans << "\n";
}
