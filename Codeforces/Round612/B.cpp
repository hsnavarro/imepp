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
const int N = 2e5+5;

int n, k, ans;
string s;
vector<string> v;
map<string, int> idx;
char l[] = {'S', 'T', 'E'};

bool can(int ida, int idb){
  string ans;
  string a = v[ida], b = v[idb];
  for(int i = 0; i < k; i++){
    for(int j = 0; j < 3; j++){
      if((l[j] == a[i] and l[j] == b[i]) or (l[j] != a[i] and l[j] != b[i] and a[i] != b[i])) ans += l[j];
    }
  }
  int pos = idx[ans];
  return (pos > ida and pos > idb);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> s;
    v.pb(s);
    idx[s] = i;
  }

  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++) ans += can(i, j);

  cout << ans << "\n";
}
