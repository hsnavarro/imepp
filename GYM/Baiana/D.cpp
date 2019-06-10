#include <bits/stdc++.h>
using namespace std;

int aa;
vector<int> inp, a;

char findWho(int a){
  if(a <= 12) return 'm';
  if(a <= 30) return 'd';
  return 'a';
}

int main(){
  for(int i = 0; i < 3; i++) cin >> aa, inp.push_back(aa);
  a = inp;
  sort(a.begin(), a.end());
  if(a[0] > 12 or a[1] > 30) cout << "invalida" << endl;
  else if(a[0] <= 12 and a[1] >= 12 and a[1] <= 30 and a[2] > 30){
    cout << findWho(inp[0]) << "-" << findWho(inp[1]) << "-" << findWho(inp[2]) << endl;
  } else cout << "ambigua" << endl;

}
