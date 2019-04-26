#include <bits/stdc++.h>
using namespace std;

int table[8][8], cnt, x, y, t, lin[10], col[10], dp[15], ds[15];
int ans[8];

bool isComplete(){
  for(int i = 0; i < 8; i++) if(!ans[i]) return false;
  return true;
}

bool check(int x, int y){
  return (!table[x][y] and !lin[x] and !col[y] and !dp[x-y+7] and !ds[x+y]);
}

void insert(int x, int y, int esc){
  ans[y] = esc ?  x+1 : 0;
  table[x][y] = lin[x] = col[y] = dp[x-y+7] = ds[x+y] = esc;
}

void bt(int x, int y){
  if(y == 8) {
    if(isComplete()){
      printf("%2d      ", ++cnt);
      for(int i = 0; i < 8; i++) 
        i == 7 ? printf("%d", ans[i]) : printf("%d ", ans[i]);
      printf("\n");
    }
    return;
  }
  if(x == 8) return bt(0, y+1);
  if(check(x, y)) insert(x, y, 1), bt(x+1, y), insert(x, y, 0);
  bt(x+1, y);
}

void reset(){
  memset(table, 0, sizeof table);
  memset(lin, 0, sizeof lin), memset(col, 0, sizeof col);
  memset(dp, 0, sizeof dp), memset(ds, 0, sizeof ds);
  memset(ans, 0, sizeof ans);
  cnt = 0;
}

int main(){
  cin >> t;
  while(t--){
    reset();
    cin >> x >> y;
    insert(x-1, y-1, 1);
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    bt(0, 0);
    if(t) printf("\n");
  }
}
