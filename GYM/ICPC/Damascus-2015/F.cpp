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

int t;
string s, a, b;
set<string> st;

void generate(int i) {
  if(i == a.size() + b.size()) {
    int cnt = 0;
    for(auto x : s) cnt += (x == '1');
    if(cnt == a.size()) {
      string ans;
      int cnt1 = 0, cnt2 = 0;
      for(auto x : s) {
        if(x == '1') ans += a[cnt1++];
        else ans += b[cnt2++];
      }
      st.insert(ans);
    }
    return;
  }

  s += '1', generate(i+1), s.pop_back();
  s += '2', generate(i+1), s.pop_back();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    st.clear();
    cin >> a >> b;
    generate(0);
    for(auto x : st) cout << x << "\n";
    cout << "\n";
  }
}

