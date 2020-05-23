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
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> s;
    int cnt = 0;
    for(auto x : s) if(x != '0') cnt++;

    cout << cnt << "\n";
    int mult = 1;

    for(int i = s.size() - 1; i >= 0; i--) {
      if(s[i] != '0') cout << mult*(s[i] - '0') << " ";
      mult = mult*10;
    }

    cout << "\n";
  }
}

