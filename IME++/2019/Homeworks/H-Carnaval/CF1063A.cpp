#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> s;
  sort(s.begin(), s.end());
  cout << s << endl;
}
