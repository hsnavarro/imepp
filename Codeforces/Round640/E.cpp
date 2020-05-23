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
const int N = 8e3+5;

int t, n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    for(int i = 0; i < n; i++) {
      int right = 0;
      int sum = 0;
      for(int left = 0; left < n; left++) {
          right = max(right, left);
          while(right < n and sum < a[i]) sum += a[right], right++;
          if(right - left >= 2 and sum == a[i]) {
            cnt++;
            break;
          }
          sum -= a[left];
      }
    }
    cout << cnt << "\n";
  }

}

