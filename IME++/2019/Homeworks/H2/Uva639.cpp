#include <bits/stdc++.h>
using namespace std;

int n, ans, cnt, table[4][4];
string s;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool in(int x, int y){
  if(x >= 0 and x < n and y >= 0 and y < n) return true;
  return false;
}

void insert(int x, int y, int esc){
  for(int i = 0; i < 4; i++){
    for(int k = 0; k <= n; k++){
      int xn = x + k*dx[i];
      int yn = y + k*dy[i];
      if(!in(xn, yn) or table[xn][yn] == 1) break;
      table[xn][yn] = (esc == 1) ? 2 : 0;
      }
    }
    (esc == 1) ? cnt++ : cnt--;
}

void bt(int x, int y){
  if(y == n) { ans = max(ans, cnt); return; }
  if(x == n) { bt(0, y+1); return; }
  if(!table[x][y]) insert(x,y,1), bt(x+1, y), insert(x,y,0);
  bt(x+1, y);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  
  while(cin >> n and n){
    ans = 0;
    for(int i = 0; i < n; i++) {
      cin >> s; 
      for(int j = 0; j < n; j++) table[i][j] = (s[j] == 'X');
    }
    bt(0, 0);
    cout << ans << endl;
  }
}
