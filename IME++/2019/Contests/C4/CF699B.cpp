#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, table[1005][1005];
map<int, int> lin, col;
string s;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> s;
    for(int j = 0; j < m; j++){
      if(s[j] == '*') lin[i]++, col[j]++, cnt++, table[i][j] = 1;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(lin[i] + col[j] == cnt + table[i][j]){
        cout << "YES" << endl;
        cout << i+1 << " " << j+1 << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
