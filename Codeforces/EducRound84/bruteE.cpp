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

int n;
int power[N];

long process(int x, int sz, int k) {
  string s = to_string(x);
  while(s.size() != sz) s = '0' + s;

  //db(s);

  long ans = 0;
  int cnt = 0;
  for(int i = 0; i < s.size(); i++) {
    if(!i or s[i] == s[i-1]) cnt++;
    else {
      if(cnt == k) ans++;
      cnt = 1;
    }
  }
  if(cnt == k) ans++;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  power[0] = 1;
  for(int i = 1; i <= n; i++) power[i] = 10*power[i-1];

  for(int i = 1; i <= n; i++) {
    for(int k = 1; k <= i; k++) { 
      long ans = 0;
      for(int j = 0; j < power[i]; j++) ans += process(j, i, k);
      cout << ans << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}
