#include <bits/stdc++.h>
using namespace std;

int n;
double sum;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = n; i >= 1; i--) sum += 1.0*i*(i-1);
  cout << fixed << setprecision(20) << sum/(1.0*n) << "\n";
}
