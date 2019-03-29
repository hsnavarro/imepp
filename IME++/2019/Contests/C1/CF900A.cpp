#include <bits/stdc++.h>
using namespace std;

int n, a, b, pos, neg;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> a >> b;
    a > 0 ? pos++ : neg++;
  }

  cout << (pos > 1 and neg > 1 ? "No" : "Yes") << endl;
}
