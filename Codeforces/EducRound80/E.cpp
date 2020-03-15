#include <bits/stdc++.h>
using namespace std;
 
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
 
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5+5, M = 2*N;

int n, m, bit[M], r;
int mn[N], mx[N], p[N], x;

void add(int p, int v) { for (p+=2; p<M; p+=p&-p) bit[p] += v; }

void update(int l, int r){
    add(l, 1);
    if(r != M) add(r+1, -1);
}

int query(int p) {
  int r = 0;
  for (p+=2; p; p-=p&-p) r += bit[p];
  return r;
}

void go(int x) {
  mn[x] = 1;
  if(p[x] <= n) mx[x] = max(mx[x], x + query(p[x]));
  else mx[x] = max(mx[x], query(p[x]));
  update(p[x]+1, r);
  p[x] = r++;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  r = n+1;
  for(int i = 1; i <= n; i++) { 
    mn[i] = mx[i] = i;
    p[i] = n - i + 1;
  }
  while(m--) cin >> x, go(x);

  for(int i = 1; i <= n; i++) {
    if(p[i] <= n) mx[i] = max(mx[i], i + query(p[i]));
    else mx[i] = max(mx[i], query(p[i]));
  }

  for(int i = 1; i <= n; i++) cout << mn[i] << " " << mx[i] << "\n";
}
