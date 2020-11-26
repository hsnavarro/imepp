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

ll eval(string s) {
  ll sum = 0, mult = 1;
  for(auto x : s) {
    if(x == '1') sum += mult;
    mult *= 2ll;
  }
  return sum;
}

set<string> s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ll X, Y;
  cin >> X >> Y;
  int sum = 0;

  for(int n = 1; n <= 63; n++) {
    for(int m = 1; m <= 63; m++) {
        string a, b; 
        while(a.size() != n) a += '1';
        while(b.size() != m) b += '0';

        string op1 = a, op2 = b + a;
        while(op1.size() <= 63 and eval(op1) <= Y) {
          if(eval(op1) >= X) s.insert(op1);
          op1 += b + a;
        }

        while(op2.size() <= 63 and eval(op2) <= Y) {
          if(eval(op2) >= X) s.insert(op2);
          op2 += b + a;
        }
    }
  }
  cout << s.size() << "\n";
}

