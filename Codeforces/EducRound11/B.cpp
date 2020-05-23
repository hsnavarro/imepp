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

int n, m;
int mt[105][4];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  
  int start = 0, row = 0;
  int cnt = 1;
  while(row < n and cnt <= m) {
    mt[row][start] = cnt;
    cnt++;
    if(start == 0) start = 3;
    else if(start == 3) start = 0, row++;
  }

  start = 1, row = 0;
  while(row < n and cnt <= m) {
    mt[row][start] = cnt;
    cnt++;
    if(start == 1) start = 2;
    else if(start == 2) start = 1, row++;
  }

  //for(int i = 0; i < n; i++) {
  //  for(int j = 0; j < 4; j++) cout << mt[i][j] << " ";
  // cout << "\n";
  //}

  vector<int> order = {1, 0, 2, 3};

  vector<int> ans;
  for(int i = 0; i < n; i++) {
    for(auto x : order) if(mt[i][x]) ans.pb(mt[i][x]);
  }

  for(auto x : ans) cout << x << " ";
  cout << "\n";
}

