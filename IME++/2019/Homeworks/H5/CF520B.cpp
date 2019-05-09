#include <bits/stdc++.h>
using namespace std;

const int N = 2e4+5;

int n, m, vis[N];
int bfs(int x = n){
  queue<pair<int, int>> q;
  q.push({x, 0});
  while(q.size()){
    int v = q.front().first; 
    int d = q.front().second;
    vis[v] = 1;
    q.pop();
    if(v == m) return d;
    if(2*v <= 2*m and !vis[2*v]) q.push({2*v, d+1});
    if(v-1 > 0 and !vis[v-1]) q.push({v-1, d+1});
  }
}

int main(){
  scanf("%d%d", &n, &m);
  printf("%d\n", bfs());
}
