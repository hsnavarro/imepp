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
const int N = (1 << 22) + 5;

int cmp[N];
vector<pair<int, string>> palPrime;

string isPalin(int x) {
  string s;
  for(int i = 0; i < 26; i++) {
    if(x & (1 << i)) s += '1';
    else s += '0';
  }

  while(s.size() and s.back() == '0') s.pop_back();

  for(int i = 0; i < s.size(); i++) {
    if(i > s.size() - 1 - i) break;
    if(s[i] != s[s.size() - 1 - i]) return "";
  }
  return s;
}

void sieve() {
  for(ll i = 2; i < N; i++) {
    if(!cmp[i]) {
      string s = isPalin(i);
      if(s.size()) palPrime.pb({i, s});
      for(ll j = i*i; j < N; j += i) cmp[j] = 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  sieve();
  string s;
  while(cin >> s) {
    int val = 0;
    for(int i = s.size() - 1; i >= 0; i--) if(s[i] == '1') val += (1 << (s.size() - 1 - i));
    for(auto x : palPrime) {
      if(x.st >= val) { cout << x.nd << "\n"; break; }
    }
  }
}

