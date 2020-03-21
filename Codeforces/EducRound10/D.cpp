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
const int N = 2e5+5;

int bit[N];

void add(int p, int v) {
  for (p+=2; p<N; p+=p&-p) bit[p] += v;
}

int query(int p) {
  int r = 0;
  for (p+=2; p; p-=p&-p) r += bit[p];
  return r;
}

int n, a, b, ans[N];
vector<int> l, r;
vector<pair<pii, int>> rng;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    l.pb(a), r.pb(b);
    rng.pb({{a, b}, i});
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  l.resize(unique(l.begin(), l.end()) - l.begin());
  r.resize(unique(r.begin(), r.end()) - r.begin());

  for(auto &x : rng) {
    x.st.st = lower_bound(l.begin(), l.end(), x.st.st) - l.begin() + 1;
    x.st.nd = lower_bound(r.begin(), r.end(), x.st.nd) - r.begin() + 1;
    add(x.st.nd, 1);
  }
  sort(rng.begin(), rng.end());
  for(int i = 0; i < rng.size(); i++) {
    int val = query(rng[i].st.nd);
    val--;
    ans[rng[i].nd] = val;
    add(rng[i].st.nd, -1);
  }

  for(int i = 0; i < n; i++) cout << ans[i] << "\n";


}

