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
const int N = 3e5+5;

// bin search + sliding window

int n, k, ps[N], a[N];
int lans, rans;

int sum(int l, int r) {
  int ans = ps[r];
  if(l-1 >= 0) ans -= ps[l-1];
  return ans;
}

bool test(int x) {
  if(!x) {
    lans = 0;
    rans = -1;
    return true;
  }

  for(int i = 0; i + x - 1 < n; i++) {
    if(x - sum(i, i + x - 1) <= k) {
      lans = i;
      rans = i + x - 1;
      return true;
    }
  }
  return false;
}

int bin() {
  int l = 0, r = n, mid;
  while(l != r) {
    mid = (l + r)/2;
    if(test(mid)) l = mid + 1;
    else r = mid;
  }
  if(!test(l)) l--;
  return l;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a[i];
  ps[0] = a[0];
  for(int i = 1; i < n; i++) ps[i] = a[i] + ps[i-1];

  int ans = bin();
  test(ans);
  //db(lans _ rans);
  for(int i = lans; i <= rans; i++) a[i] = 1;

  cout << ans << "\n";
  for(int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";

}

