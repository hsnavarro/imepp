#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
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
typedef vector<vi> vii;
 
const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e3+5;
 
int n, a[N], freq[N];
vector<int> ax;
 
int test(int l, int x){
  memset(freq, 0, sizeof freq);
  for(int i = 0; i < n; i++) {
    if(i < l or i >= l+x){
      if(freq[a[i]]) return 0;
      freq[a[i]]++;
    }
  }
  return 1;
}
 
int test(int x){
  for(int l = 0; l+x-1 < n; l++) if(test(l, x)) return 1;
  return 0;
}
 
int bin(int l = 0, int r = n){
  int mid;
  while(l != r){
    mid = (l+r)/2;
    if(test(mid)) r = mid;
    else l = mid+1;
  }
  return l;
}
 
int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i], ax.pb(a[i]);
  sort(ax.begin(), ax.end());
  for(int i = 0; i < n; i++) a[i] = lower_bound(ax.begin(), ax.end(), a[i]) - ax.begin();
  cout << bin() << "\n";
}
