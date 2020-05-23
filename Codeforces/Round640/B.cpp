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
int n, k;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> k;
    vector<int> even, odd;
    if(k == 1) {
      cout << "YES\n";
      cout << n << "\n";
      continue;
    }

    //even
    int sum = 0;
    for(int i = 0; i < k-1; i++) {
      even.push_back(2);
      sum += 2;
    }

    even.push_back(n - sum);

    sum = 0;
    for(int i = 0; i < k-1; i++){
      odd.push_back(1);
      sum++;
    }

    odd.push_back(n - sum);

    if((even.back() - even[0]) % 2 == 0 and even.back() > 0) {
      cout << "YES\n";
      for(auto x : even) cout << x << " ";
      cout << "\n";
    } else if((odd.back() - odd[0]) % 2 == 0 and odd.back() > 0) {
      cout << "YES\n";
      for(auto x : odd) cout << x << " ";
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }
}

