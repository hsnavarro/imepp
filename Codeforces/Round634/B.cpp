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

int t, n, a, b;
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> a >> b;
    s.clear();
    char ch = 'a';

    int bb = b;
    while(b--) s += ch, ch++;
    a -= bb;
    if(a) while(a--) s += s.back();
    
    int ptr = 0;
    while(s.size() < n) s += s[ptr], ptr++;

    cout << s << "\n";
  }
}
