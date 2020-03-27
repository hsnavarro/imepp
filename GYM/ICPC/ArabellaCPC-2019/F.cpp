#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

// dp[idx song][pos] = 1: win / 0: lose
int n, p, a[N], fail[N], dp[N][N];
int bit[N];

void update(int p) {
  for (p+=2; p<N; p+=p&-p) bit[p] += 1;
}

int sum(int p) {
  int r = 0;
  for (p+=2; p; p-=p&-p) r += bit[p];
  return r;
}


int cw(int x, int i) { 
  int s = sum(x);
  int sz = n-i+1;
  x -= s;
  int aux = a[i] % sz;
  x = (x + aux) % sz;
  x += s;
  return x;
}

int acw(int x, int i) { 
  int s = sum(x);
  int sz = n-i+1;
  x -= s;
  int aux = a[i] % sz;
  x = (x + sz - a[i]) % sz;
  x += s;
  return x;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> p;
  p--;
  for(int i = 1; i < n; i++) cin >> a[i];
  for(int i = 1; i < n; i++) cin >> fail[i], fail[i]--;
  dp[1][cw(p, 1)] = (cw(p, 1) != fail[1]);
  dp[1][acw(p, 1)] = (acw(p, 1) != fail[1]);
  update(fail[1]);
  for(int i = 2; i < n; i++) {
    for(int k = 0; k < n; k++) {
      if(dp[i-1][k]) {
        dp[i][cw(k, i)] = (cw(k, i) != fail[i]);
        dp[i][acw(k, i)] = (acw(k, i) != fail[i]);
      }
    } 
    update(fail[i]);
  }

  for(int k = 0; k < n; k++) if(dp[n-1][k]) return cout << "Yes\n", 0;
  cout << "No\n";
}
