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

// maior primeiro, menor segundo
priority_queue<piii> pq;

int t, n;
vector<int> a;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    a.resize(n, 0);
    pq.push({n, {0, n-1}});
    int cnt = 1;
    while(pq.size()) {
      int l = -pq.top().nd.st;
      int r = pq.top().nd.nd;
      pq.pop();

      int tam = r - l + 1;

      int mid;
      mid = (tam & 1) ? (l + r)/2 : (l + r - 1)/2;
      a[mid] = cnt;
      if(mid-1 >= l) pq.push({mid - l, {-l, mid-1}});
      if(mid+1 <= r) pq.push({r - mid, {-mid-1, r}});
      cnt++;
    }

    for(auto x : a) cout << x << " ";
    cout << "\n";
  }

}

