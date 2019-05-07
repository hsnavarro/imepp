#include<bits/stdc++.h>
using namespace std;

int n, q, c, x, y, s; 
int table[105][105][15];
int prefix[105][105][15];

int quant(int x1, int y1, int x2, int y2, int p){
  return prefix[x2][y2][p] - prefix[x1-1][y2][p] - prefix[x2][y1-1][p] + 
    prefix[x1-1][y1-1][p];
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q >> c;
  while(n--){
    cin >> x >> y >> s;
    table[x][y][s]++;
  }
  
  for(int i = 0; i < 15; i++) prefix[0][0][i] = table[0][0][i];
  for(int p = 0; p < 15; p++){
    for(int x = 1; x < 105; x++){
      for(int y = 1; y < 105; y++){
        prefix[x][y][p] = prefix[x-1][y][p] + prefix[x][y-1][p] 
          - prefix[x-1][y-1][p] + table[x][y][p];
      }
    }
  }
  
  int t, x1, y1, x2, y2;
  while(q--){
    cin >> t >> x1 >> y1 >> x2 >> y2;
    int sum = 0;
    for(int p = 0; p < 15; p++) sum += ((t+p)%(c+1)) * 
      quant(x1, y1, x2, y2, p);
    cout << sum << endl;
  }
}
