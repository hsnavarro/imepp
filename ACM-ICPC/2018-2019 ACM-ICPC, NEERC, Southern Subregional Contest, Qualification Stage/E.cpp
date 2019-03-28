#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, m, c, a[N], bit[N], st[4*N], lazy[4*N];
deque<int> dq[N];

void push (int p, int l, int r) {
 if (lazy[p]) {
    st[p] = (r-l+1)*lazy[p];
    if (l != r) {
      lazy[2*p] = lazy[p];
      lazy[2*p+1] = lazy[p];
   }
  lazy[p] = 0;
  }
}

int queryt (int p, int l, int r, int i, int j) {
 push(p, l, r);
 if (r < i or j < l) return 0;
 if (i <= l and r <= j) return st[p];
 int x = queryt(2*p, l, (l+r)/2, i, j);
 int y = queryt(2*p+1, (l+r)/2+1, r, i, j);
 return x+y;
}

void updatet (int p, int l, int r, int i, int j, int k) {
 push(p, l, r);
 if (r < i or j < l) return;
 if (i <= l and r <= j) {
    lazy[p] = k;
    push(p, l, r);
    return;
 }
 updatet(2*p, l, (l+r)/2, i, j, k);
 updatet(2*p+1, (l+r)/2+1, r, i, j, k);
 if (l != r) st[p] = st[2*p] + st[2*p+1];
}

void add(int p, int v) { for (p+=2; p<N; p+=p&-p) bit[p] += v; }

void update(int l, int r, int val){
    add(l, val);
    if(r != N) add(r+1, -val);
}

int query(int p) {
    int r = 0;
    for (p+=2; p; p-=p&-p) r += bit[p];
    return r;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], dq[a[i]].push_back(i);;
  cin >> m;
  while(m--){
    cin >> c;
    while(dq[c].size() and query(dq[c].front())) dq[c].pop_front();
    while(dq[c].size() and query(dq[c].back())) dq[c].pop_back();
    if(dq[c].size() < 2) continue;
    update(dq[c].front(), dq[c].back(), 1);
    updatet(1, 1, n, dq[c].front(), dq[c].back(), c);
  }
  for(int i = 1; i <= n; i++) cout << (queryt(1, 1, n, i, i) ? queryt(1, 1, n, i, i) : a[i]) << " ";
  cout << endl;
}
