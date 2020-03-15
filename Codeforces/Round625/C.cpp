#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

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
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

string cur;
int n, cnt;

void erase(int j) {
  cnt++;
  string aux;
  for(int i = 0; i < cur.size(); i++) 
    if(i != j) aux += cur[i];
  cur = aux;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  cin >> cur;
  int cond;
  do {
    int stop = 0;
    cond = 0;
    for(int i = 25; i >= 0; i--) {
      for(int j = 0; j < cur.size(); j++) {
        if(cur[j] - 'a' != i) continue;
        if(j - 1 >= 0 and cur[j] - cur[j-1] == 1) {
          stop = 1;
          erase(j);
          cond = 1;
          break;
        }
        if(j + 1 < cur.size() and cur[j] - cur[j+1] == 1) {
          stop = 1;
          erase(j);
          cond = 1;
          break;
        }

      }
      if(stop) break;
    }

  } while(cond);
  //cout << cur << "\n";
  cout << cnt << "\n";
}
