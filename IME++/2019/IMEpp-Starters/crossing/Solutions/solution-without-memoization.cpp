#include <bits/stdc++.h>
using namespace std;

string a, b;

int lcs(int i, int j){
  if(i == 0 or j == 0) return 0;
  if(a[i-1] == b[j-1]) return 1 + lcs(i-1, j-1);
  else return max(lcs(i-1, j), lcs(i, j-1));
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  cout << lcs(a.size(), b.size()) << endl;
}
