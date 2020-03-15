#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e3+5;

int main(){
  
  ios_base::sync_with_stdio(0), cin.tie(0);
  
  int n , c , s;

  while(cin >> n >> c >> s){
    int f[N] , x , pos = 1;
    memset(f,0,sizeof(f));
    f[1] = 1;
    for(int i = 1 ; i <= c ; i++){
      cin >> x;
      if(x == 1){
        if(pos == n) pos = 1;
        else pos++;
      }
      else{
        if(pos == 1) pos = n;
        else pos--;
      }
      f[pos]++;
    }
    cout << f[s] << "\n";
  }

}
