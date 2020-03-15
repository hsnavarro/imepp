#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int k, c, a, b, idx, res[N];
string s, t;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> k;
  cin >> s >> t;
  
  for(int i = 0; i < k; i++){
    a = s[i] - 'a';
    b = t[i] - 'a';
    res[i] = (a + b)/2 + c;
  
    idx = i;
    while(res[idx] >= 26){
      res[idx] -= 26;
      res[idx-1]++;
      idx--;
    }

    c = 13 * ((a+b)&1);
  }
  for(int i = 0; i < k; i++) cout << char(res[i] + 'a');
  cout << endl;
}
