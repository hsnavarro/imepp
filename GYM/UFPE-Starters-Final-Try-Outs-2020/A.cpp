#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
vector<int> d1, d2;

void manacher(){
  // impar
  d1.resize(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
    d1[i] = k--;
    if (i + k > r) l = i - k, r = i + k;  
  }
  // par
  d2.resize(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;  
    d2[i] = k--;
    if (i + k > r) l = i - k - 1, r = i + k ;
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  cin >> s;
  manacher();
  int ok = 0;
  //for(auto x : d1) cerr << 2*(x-1)+1 << " ";
  //cerr << endl;
  //for(auto x : d2) cerr << 2*(x-1)+2 << " ";
  //cerr << endl;

  if(m&1) {
    for(auto x : d1) if((2*(x-1)+1) >= m) ok = 1; 
  }
  else {
    for(auto x : d2) if((2*(x-1)+2) >= m) ok = 1;
  }
  cout << (ok ? "Accept" : "Reject") << endl;
}
