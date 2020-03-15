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
const int N = 1e6+5;

ll n, m, a[N];
map<ll, ll> freq;
int cnt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i], freq[a[i]]++;
  
  for(auto x : freq) {
    for(ll k = x.st; k <= m; k += x.st) cnt[k] += x.nd;
  }

  int mx = -1, mmc = -1;
  for(int i = 1; i <= m; i++) {
    if(cnt[i] > mx) mx = cnt[i], mmc = i;
  }

  if(mmc == -1) cout << 1 << " " << 0 << "\n\n";
  else {
    cout << mmc << " " << mx << "\n";
    for(int i = 0; i < n; i++) if(mmc % a[i] == 0) cout << i+1 << " ";
    cout << "\n";
  }

}

