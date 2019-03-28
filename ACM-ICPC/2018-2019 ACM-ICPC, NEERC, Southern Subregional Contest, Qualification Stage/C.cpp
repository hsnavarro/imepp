#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

typedef long long ll;

int n, ans;
ll a[N], x;
priority_queue<ll, vector<ll>, greater<ll>> pq;

bool ok(int x){ return (x != 0) and !(x & (x - 1)); }

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for(int i = 1; i < n; i++)
    if(a[i] % a[0] != 0 or !ok(a[i]/a[0])) return cout << -1 << endl, 0;

  for(int i = 0; i < n; i++) pq.push(a[i]);
  while(pq.size() > 1){
    x = pq.top();
    pq.pop();
    ans += (x != pq.top());
    if(x == pq.top()) pq.pop();
    pq.push(2*x);
  }

  cout << ans << endl;
}
