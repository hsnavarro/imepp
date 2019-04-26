#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

int a, t, lin[9], col[9], reg[3][3], table[9][9];

bool ok(int x, int y, int i){
  return !((lin[x] | col[y] | reg[x/3][y/3]) & (1 << i)); 
}

void insert(int x, int y, int i, int esc){
  if(i == 0) return;
  table[x][y] += esc*i;
  lin[x] += esc*(1 << i);
  col[y] += esc*(1 << i);
  reg[x/3][y/3] += esc*(1 << i);
}

bool bt(int x, int y){
  if(y == 9) return true;
  if(x == 9) return bt(0, y+1);
  if(table[x][y]) return bt(x+1, y);
    for(int i = 1; i <= 9; i++) {
      if(ok(x, y, i)) {
        insert(x, y, i, 1); 
        if(bt(x+1, y)) return true;
        insert(x, y, i, -1);
      }
    }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cl(lin, 0), cl(col, 0), cl(reg, 0), cl(table, 0);

    for(int i = 0; i < 9; i++) 
      for(int j = 0; j < 9; j++) cin >> a, insert(i, j, a, 1);


    if(!bt(0, 0)) cout << "No solution" << endl;
    else{
      for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) cout << table[i][j] << " ";
        cout << endl;
      }
    }
  }
}
