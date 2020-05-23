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

#define int long long

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;


int st[4*N], n, q;
vector<int> a, d;
vector<piii> qs;

void build(int p = 1, int l = 1, int r = d.size() - 1) {
  if(l == r) { st[p] = d[l]; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = max(st[2*p], st[2*p+1]);
}

int query(int i, int j, int p = 1, int l = 1, int r = d.size() - 1) {
  if(l >= i and j >= r) return st[p];
  if(l > j or r < i) return 0;
  return max(query(i, j, 2*p, l, (l+r)/2), query(i, j, 2*p+1, (l+r)/2+1, r));
}

void update(int idx, int v, int p = 1, int l = 1, int r = d.size() - 1) {
  if(l == r) { st[p] = v; return; }
  if(idx <= (l+r)/2) update(idx, v, 2*p, l, (l+r)/2);
  else update(idx, v, 2*p+1, (l+r)/2+1, r);
  st[p] = max(st[2*p], st[2*p+1]);
}

void print() {
  for(int i = 1; i < d.size(); i++) {
    int q = query(i, i);
    db(i _ q);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  a.resize(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) a.push_back(a[i]);
  d.push_back(0);
  for(int i = 1; i+1 < a.size(); i++) d.push_back(abs(a[i+1] - a[i]));
  cin >> q;
  int op, b, c;
  build();
  //print();
  while(q--) {
    cin >> op >> b >> c;
    if(op == 1) {
      int idx = b;
      while(idx < a.size()) {
        a[idx] = c;
        if(idx+1 < a.size()) {
          d[idx] = abs(a[idx+1] - a[idx]);
          update(idx, d[idx]);
        }
        if(idx-1 >= 1) {
          d[idx-1] = abs(a[idx] - a[idx-1]);
          update(idx-1, d[idx-1]);
        }
         
        idx += n;
      }
      //print();
    } else {
      int ori = b;
      int l = b, r = b + n - 1, mid;
      while(l != r) {
        mid = (l+r)/2;
        int res = query(ori, mid);
        if(res > c) r = mid;
        else l = mid + 1;
      }
      while(l < d.size() - 1 and query(ori, l) <= c) l++;
      while(l > n) l -= n;
      cout << l << "\n";
    }
  }
}

