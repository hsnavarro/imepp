#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

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

int t;
int bit[N];
int pref[N], suf[N];
int n, a[N];

void add(int p, int v = 1) {
  for (p+=2; p < n+5; p+=p&-p) bit[p] += v;
}

int query(int p) {
  int r = 0;
  for (p+=2; p; p-=p&-p) r += bit[p];
  return r;
}

int query(int l, int r) { return query(r) - query(l-1); }

void clear(int n) { for(int i = 0; i < n+5; i++) bit[i] = 0; };

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pref[i] = suf[i] = 0;

    clear(n);
    for(int i = 1; i <= n; i++) {
      if(!query(a[i], a[i])) add(a[i]);
      if(query(i) == i) pref[i] = 1;
    }
    clear(n);
    
    for(int i = n; i >= 1; i--) {
      if(!query(a[i], a[i])) add(a[i]);
      if(query(n-i+1) == n-i+1) suf[i] = 1;
    } 

    //for(int i = 1; i <= n; i++) db(pref[i] _ suf[i]);
    
    int cnt = 0;
    for(int i = 1; i+1 <= n; i++) if(pref[i] and suf[i+1]) cnt++;

    cout << cnt << "\n";
    for(int i = 1; i+1 <= n; i++) 
      if(pref[i] and suf[i+1]) cout << i << " " << n-i << "\n";
  }
}

