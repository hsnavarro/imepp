#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

int t, n;
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    cin >> s;
    string small, big;
    int idx = 0;
    while(idx < n and s[idx] != '1') {
      if(s[idx] == '2') small += '1', big += '1';
      else small += '0', big += '0';
      idx++;
    }
    if(idx < n) small += '0', big += '1', idx++;

    while(idx < n) {
      small += s[idx];
      big += '0';
      idx++;
    }
    cout << small << "\n";
    cout << big << "\n";
  }
}

