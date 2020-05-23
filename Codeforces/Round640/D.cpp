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
int ptr[2], pre[2], moves, tot[2];
int n, a[1005];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    ptr[0] = 1, ptr[1] = n-1;
    pre[0] = a[0];
    pre[1] = 0;
    tot[0] = a[0];
    tot[1] = 0;

    moves = 1;
    int turn = 1;
    while(ptr[0] <= ptr[1]) {
      int sum = 0;
      if(turn == 1) {
        while(ptr[0] <= ptr[1] and sum <= pre[0]) sum += a[ptr[1]], ptr[1]--;
        pre[1] = sum;
        tot[1] += sum;
      } else {
        while(ptr[0] <= ptr[1] and sum <= pre[1]) sum += a[ptr[0]], ptr[0]++;
        pre[0] = sum;
        tot[0] += sum;
      }

      moves++;
      turn = turn^1;
    }

    cout << moves << " " << tot[0] << " " << tot[1] << "\n";
  }
}

