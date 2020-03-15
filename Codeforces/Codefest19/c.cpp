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
const int N = 1e5+5;

int n, A[N][4][4];
vector<vector<int>> base(4, vector<int> (4, 0));

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  base[0] = { 8, 9, 1, 13 };
  base[1] = {3, 12, 7, 5 };
  base[2] = {0, 2, 4, 11 };
  base[3] = {6, 10, 15, 14};

  for(int k = 0; k < (n/4)*(n/4); k++)
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++) A[k][i][j] = base[i][j] + 1ll*16*k;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << A[j/4 + (n/4)*(i/4)][i%4][j%4] << " ";
    }
    cout << endl;
  }

}
