#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
vector<int> xa, ya;
vector<pair<int, int>> pts;
int n, x[N], y[N], bit[N];

void add(int p){ for(p += 2; p < N; p += p & -p) bit[p] += 1; }

int query(int p){
  int r = 0;
  for(p += 2; p; p -= p & -p) r += bit[p];
  return r;
}

int query(int l, int r){ return query(r) - (l ? query(l-1) : 0); }

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> x[i] >> y[i];
    xa.push_back(x[i]);
    ya.push_back(y[i]);
  }

  sort(xa.begin(), xa.end());
  sort(ya.begin(), ya.end());
  for(int i = 1; i <= n; i++){
    int xx = lower_bound(xa.begin(), xa.end(), x[i]) - xa.begin() + 1;
    int yy = lower_bound(ya.begin(), ya.end(), y[i]) - ya.begin() + 1;
    pts.push_back({xx, yy});
  }
  sort(pts.begin(), pts.end());
  int cnt = 0;
  for(int i = 0; i < pts.size(); i++){
    memset(bit, 0, sizeof bit);
    for(int j = i; j >= 0; j--) {
      add(pts[j].second);
      int l = min(pts[j].second, pts[i].second);
      int r = max(pts[j].second, pts[i].second);
      if(query(l, r) == 2) cnt++;
    }
  }

  cout << cnt << "\n";
}
