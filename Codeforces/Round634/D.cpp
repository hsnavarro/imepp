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
const int N = 1e5+5;

int t;

char grid[9][9];
vector<char> v;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    v.clear();
    for(int i = 1; i <= 9; i++) v.push_back(char(i + '0'));

    for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++) cin >> grid[i][j];

    vector<pair<int, int>> vs;
    vs.pb({0, 0});
    vs.pb({1, 3});
    vs.pb({2, 6});
    vs.pb({3, 1});
    vs.pb({4, 4});
    vs.pb({5, 7});
    vs.pb({6, 2});
    vs.pb({7, 5});
    vs.pb({8, 8});

    for(auto x : vs) {
      int ptr = 0;
      while(v[ptr] == grid[x.st][x.nd]) ptr++;
      grid[x.st][x.nd] = v[ptr];
    }


    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) cout << grid[i][j];
      cout << "\n";
    }
  }
}
