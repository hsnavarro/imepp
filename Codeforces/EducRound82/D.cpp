#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int t, m, a;
ll n;
map<ll, ll> freq;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    freq.clear();
    int cnt = 0;
    cin >> n >> m;
    ll sum = 0;
    while(m--) cin >> a, sum += a, freq[a]++;
    if(sum < n) { cout << -1 << "\n"; continue; }
    else {
      for(int i = 0; i < 64; i++) {
        if(n & (1ll << i)) {
          if(freq[(1ll << i)]) freq[(1ll << i)]--;
          else {
            for(int x = i+1; x < 64; x++) {
              if(freq[(1ll << x)]) {
                freq[(1ll << x)]--;
                for(int j = x-1; j >= i; j--) freq[(1ll << j)]++, cnt++;
                break;
              } 
            }
          }
        }
        if(i+1 < 64) freq[(1ll << (i+1))] += freq[(1ll << i)]/2;
      }
      cout << cnt << "\n";
    }
  }
}
