#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<string> a, b;
vector<pair<int, int>> answer;
string in;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> l >> c;
  for(int i = 0; i < l; i++) cin >> in, a.push_back(in);
  for(int i = 0; i < l; i++) cin >> in, b.push_back(in);

  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      if(a[i][j] != b[i][j]) cout << i+1 << " " << j+1 << endl;
    }
  }

}
