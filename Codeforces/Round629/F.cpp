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
const int N = 2e5+5;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll n, k, s1[N], s2[N], num1[N], num2[N];
vector<ll> a;
map<ll, ll> freq;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i], freq[a[i]]++;
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());

  for(int i = 1; i < a.size(); i++) {
    num1[i] = num1[i-1] + freq[a[i-1]];
    s1[i] = s1[i-1] + num1[i] * (a[i] - a[i-1]);
  }

  for(int i = a.size() - 2; i >= 0; i--) {
    num2[i] = num2[i+1] + freq[a[i+1]];
    s2[i] = s2[i+1] + num2[i] * (a[i+1] - a[i]);
  }

  ll ans = LINF;
  for(int i = 0; i < a.size(); i++) {
    if(k <= freq[a[i]]) ans = 0;
    else {
      ll kn = k - freq[a[i]];
      if(i-1 >= 0 and num1[i] >= kn) 
        ans = min(ans, s1[i-1] + num1[i]*(a[i] - 1 - a[i-1]) + kn);
      if(i+1 < a.size() and num2[i] >= kn) 
        ans = min(ans, s2[i+1] + num2[i]*(a[i+1] - a[i] - 1) + kn);
      if(!i or i == a.size() - 1) continue;

      ans = min(ans, s1[i-1] + num1[i]*(a[i] - 1 - a[i-1]) + s2[i+1] + num2[i]*(a[i+1] - a[i] - 1) + kn);
    }
  }
  cout << ans << "\n";
}

