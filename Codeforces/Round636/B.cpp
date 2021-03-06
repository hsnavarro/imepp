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
const int N = 1e5+5;

int t, n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    int k = n/2;
    if(k & 1) cout << "NO\n";
    else {
      cout << "YES\n";
      ll sum1 = 0, sum2 = 0;
      vector<ll> answer(n);
      for(int i = 0; i < k; i++) answer[i] = 2ll*(i+1ll), sum1 += 2ll*(i+1ll);
      for(int i = k; i < n-1; i++) answer[i] = 1ll+2ll*(i-k), sum1 -= 1ll+2ll*(i-k);
      answer[n-1] = sum1;

      for(auto x : answer) cout << x << " ";
      cout << "\n";
    }
  }
}

