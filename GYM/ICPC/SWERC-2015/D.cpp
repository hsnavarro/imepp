#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int n, m;
int freq[N];


int main() {
  cin >> n >> m;

  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++) freq[i+j]++;

  int mx = -1;
  for(int i = 0; i < N; i++) mx = max(mx, freq[i]);

  for(int i = 0; i < N; i++) if(freq[i] == mx) cout << i << "\n";
}
