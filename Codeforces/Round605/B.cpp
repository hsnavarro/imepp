#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int q, freq[4];
string s, ans;

int pos(char x){
  if(x == 'R') return 0;
  if(x == 'U') return 1;
  if(x == 'L') return 2;
  return 3;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  while(q--){
    for(int i = 0; i < 4; i++) freq[i] = 0;
    ans.clear();
    cin >> s;
    for(auto x : s) freq[pos(x)]++;

    int res1 = min(freq[0], freq[2]), res2 = min(freq[1], freq[3]);
    if(!res1 and res2) res2 = 1;
    if(!res2 and res1) res1 = 1;

    cout << 2*(res1+res2) << "\n";
    for(int i = 0; i < res2; i++) cout << 'U';
    for(int i = 0; i < res1; i++) cout << 'L';
    for(int i = 0; i < res2; i++) cout << 'D';
    for(int i = 0; i < res1; i++) cout << 'R';
    cout << "\n";
  }







}
