#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+ 5;

vector<pair<int, int>> v;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  v.resize(3);
  cin >> v[0].st >> v[0].nd;
  cin >> v[1].st >> v[1].nd;
  cin >> v[2].st >> v[2].nd;

  int cond = 0;

  for(int i = 0; i < (1 << 3); i++) {
    set<int> s;
    int sum = 0;
    for(int j = 0; j < 3; j++) { 
      if(i & (1 << j)) s.insert(v[j].st), sum += v[j].nd;
      else s.insert(v[j].nd), sum += v[j].st;
    }

    if(s.size() == 1 and *(s.begin()) == sum) cond = 1;
  }

  for(int k = 0; k < 3; k++) {
    for(int op = 0; op < 2; op++) {
      for(int i = 0; i < (1 << 3); i++) {
        set<int> s;
        int sum1 = 0;
        if(op) s.insert(v[k].st), sum1 += v[k].nd;
        else s.insert(v[k].nd), sum1 += v[k].st;
        int sum = 0;

        set<int> t;
        for(int j = 0; j < 3; j++) {
          if(j == k) continue;
          if(i & (1 << j)) t.insert(v[j].nd), sum += v[j].st;
          else t.insert(v[j].st), sum += v[j].nd;
        }
        s.insert(sum);

        if(s.size() == 1 and t.size() == 1 and sum1 + *(t.begin()) == *(s.begin())) cond = 1;
      }
    }
  }
  cout << (cond ? "YES\n" : "NO\n");
}
