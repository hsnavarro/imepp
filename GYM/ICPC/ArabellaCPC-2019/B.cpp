#include <bits/stdc++.h>
using namespace std;

int n, k, t;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n >> k;
    if((k & 1 and n != k+1) or (k%2 == 0 and n > k)) cout << "Kilani\n";
    else cout << "Ayoub\n";
  }
}
