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

int q, n, a, b, freq[N], freq2[N];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> add[N];

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  while(q--){
    cin >> n;
    while(pq.size()) pq.pop();
    for(int i = 0; i <= n; i++) freq[i] = 0, freq2[i] = 0, add[i].clear();
    for(int i = 0; i < n; i++) cin >> a >> b, freq[a]++, freq2[a] += b;
    for(int i = 0; i <= n; i++) if(freq[i]) 
      add[freq[i]].push_back({freq2[i], freq[i]});
    ll sum = 0, sum2 = 0;
    for(int i = n; i >= 1; i--) {
      for(auto x : add[i]) pq.push(x);
      if(pq.size()) sum += i, sum2 += min(i, pq.top().st), pq.pop();
    }
    cout << sum << " " << sum2 << "\n";
  }
}
