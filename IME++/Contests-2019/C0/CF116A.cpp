#include <bits/stdc++.h>
using namespace std;

int n, a, b, sum, mx;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> a >> b;
    sum -= a;
    sum += b;
    mx = max(mx, sum);
  }
  cout << max(mx, sum) << endl;
}
