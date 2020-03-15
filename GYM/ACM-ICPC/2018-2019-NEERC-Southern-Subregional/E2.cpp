#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, m, c, a[N], bit[N], bit2[N];
deque<int> dq[N];

void update(int l, int r, int val){
  for(int i = l; i < N; i+=i&-i) bit[i] += val;
  for(int i = r + 1; i < N; i+=i&-i) bit[i] -= val;
}

int query(int p) {
    int r = 0;
    for (p+=2; p; p-=p&-p) r += bit[p];
    return r;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  updatebit(1, 4, 10);
  updatebit(3, 4, 5);
  for(int i = 1; i <= n; i++) cout << query1(i) << " ";
  cout << endl;
  for(int i = 1; i <= n; i++) cin >> a[i], dq[a[i]].push_back(i);;
  cin >> m;
  while(m--){
    cin >> c;
    while(dq[c].size() and query(dq[c].front())) dq[c].pop_front();
    while(dq[c].size() and query(dq[c].back())) dq[c].pop_back();
    if(dq[c].size() < 2) continue;
    update(dq[c].front(), dq[c].back(), 1);
    updatebit(dq[c].front(), dq[c].back(), c);
  }
  for(int i = 1; i <= n; i++) cout << (bit2[i] ? bit2[i] : a[i]) << " ";
  cout << endl;
}
