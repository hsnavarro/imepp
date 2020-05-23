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

string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  getline(cin, s);
  int a = s[0] - '0';
  int b = s[4] - '0';
  int c = s[8] - '0';

  //db(a _ b _ c);

  cout << (a+b == c ? "YES\n" : "NO\n");
}
