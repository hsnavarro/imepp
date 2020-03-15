#include <bits/stdc++.h>
using namespace std;

long long n, h;
vector<vector<long long>> grid;

int main(){
  scanf("%lld %lld", &n, &h);  
  grid.resize(n);
  for(int i = 0; i < n; i++){
    grid[i].resize(h);
    for(int j = 0; j < h; j++) scanf("%lld", &grid[i][j]);
  }

  for(int j = 1; j < h; j++){
    for(int i = 0; i < n; i++){
      long long mx = 0;
      if(i-1 >= 0) mx = max(mx, grid[i-1][j-1]);
      mx = max(mx, grid[i][j-1]);
      if(i+1 < n) mx = max(mx, grid[i+1][j-1]);
      grid[i][j] += mx;
    }
  }

  long long ans = -1;
  for(int i = 0; i < n; i++) ans = max(ans, grid[i][h-1]);
  printf("%lld\n", ans);
}
