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
const int N = 1e2+5;

int n, m, q, ans;
vector<int> v;

struct query {
  int a, b, c, d;
};

vector<query> qs;

void brute(vector<int> &v) {
  if(v.size() == n) {
    int scr = 0;
    for(auto x : qs) if(v[x.b-1] - v[x.a-1] == x.c) scr += x.d;
    ans = max(ans, scr);
    return;
  }

  for(int i = v.size() ? v.back() : 1; i <= m; i++) v.push_back(i), brute(v), v.pop_back();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> q;
  qs.resize(q);
  for(int i = 0; i < q; i++) cin >> qs[i].a >> qs[i].b >> qs[i].c >> qs[i].d;
  brute(v);
  cout << ans << "\n";
}
