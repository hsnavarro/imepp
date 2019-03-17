#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

int n, aux1, aux2, res, a, pre[105], pro[105];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    aux1 += a;
    aux2 += (1 - a);
    pre[i] = aux1;
    pro[i] = aux2;
  }

  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      res = max(res, pro[j] - (i ? pro[i-1] : 0) + (i ? pre[i-1] : 0) + pre[n-1] - (j+1 ? pre[j] : 0));
    }
  }
  

  cout << res << endl;
}
