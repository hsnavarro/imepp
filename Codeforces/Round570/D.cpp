#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second

#define int long long

typedef pair<int, int> pii;
typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 5;

int q, n, a, freq[N];
priority_queue<int> pq;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  while(q--){
    cin >> n;
    while(pq.size()) pq.pop();
    for(int i = 0; i <= n; i++) freq[i] = 0;
    for(int i = 0; i < n; i++) cin >> a, freq[a]++;
    for(int i = 0; i <= n; i++) if(freq[i]) pq.push(freq[i]);
    ll sum = 0;
    int mx = pq.top();
    for(int i = mx; i >= 0; i--) if(pq.size() and pq.top() >= i) {
      sum += i, pq.pop();
    }
    cout << sum << "\n";
  }

}
