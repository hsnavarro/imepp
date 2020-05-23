#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+ 5;

int n, a[N], b[N], k, rng;

bool test(int x) {
  for(int i = 0; i < n; i++) b[i] = 0;

  ll sum = 0;
  for(int i = 0; i < n; i++) {
    if(i >= rng) sum -= (a[i-rng] + b[i-rng]);
    sum += a[i];
    if(i >= rng-1) {
      if(sum == 0) {
        if(x) b[i] = 1, x--, sum++;
        else return false;
        if(x) b[i-1] = 1, x--, sum++;
        else return false;
      }

      if(sum == 1) {
        if(x) {
          if(b[i]) b[i-1] = 1;
          else b[i] = 1;
          x--, sum++;
        }
        else return false;
      }
    }
  }
  return x >= 0;
}

int bs(int l = 0, int r = n) {
  int mid;
  while(l != r) {
    mid = (l+r)/2;
    if(!test(mid)) l = mid+1;
    else r = mid;
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> rng;
  int ks;
  while(k--) {
    cin >> ks;
    a[ks]++;
  }

  cout << bs() << "\n";
}
