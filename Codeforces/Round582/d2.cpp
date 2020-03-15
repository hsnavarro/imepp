#include <bits/stdc++.h>
using namespace std;

#define int long long
#define st first
#define nd second

const int N = 2e5 + 5;
const int LINF = 0x3f3f3f3f3f3f3f3f;

int n, a, k, s[N];

pair<int, int> next(pair<int, int> a){ return {2*a.st, 2*a.nd + 1}; }
int rng(int l, int r) { return s[r] - (l ? s[l-1] : 0); }

int bin(int l, int r, int cnt){
  r = min(r, N-1);
  int mid, init = l;
  while(l != r){
    mid = (l+r)/2;
    if(rng(init, mid) + cnt >= k) r = mid;
    else l = mid + 1;
  }
  return l;
}

pair<int, int> test(int x){
  int cnt = 0, op = 0, aux = 0;
  pair<int, int> range = {x, x};
  while(range.st < N and cnt < k){
    int r = bin(range.st, range.nd, cnt);
    cnt += rng(range.st, r);
    op += rng(range.st, r)*aux;
    aux++, range = next(range);
  }
  return { cnt < k, op }; 
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) 
    cin >> a, mn = min(mn, a), mx = max(mx, a), s[a]++;
  for(int i = 1; i < N; i++) s[i] += s[i-1];
  pair<int, int> ans = {1, LINF};
  int idx;
  for(int i = 1; i < N; i++) ans = min(ans, test(i));
  cout << ans.nd << "\n";
}
