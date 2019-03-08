#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

#define int long long

int n, q, l, r, sum;
vector<int> v;
int freq[N];

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end(), greater<int>());
  while(q--){
    cin >> l >> r;
    freq[l]++, freq[r+1]--;
  }
  for(int i = 1; i <= n; i++) freq[i] += freq[i-1];
  sort(freq, freq + n + 1, greater<int>());
  for(int i = 0; i <= n; i++) sum += freq[i]*v[i];
  cout << sum << endl;
}
