#include <bits/stdc++.h>
using namespace std;

int t;
string in, a, b;

void func(string& in, string& a, string& b){
  for(int i = in.size() - 1; i >= 0; i--){
    if(in[i] != '4'){
      a[i] = in[i];
      b[i] = '0';
    }
    else{
      a[i] = '1';
      b[i] = in[i] - a[i] + '0';
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  int cnt = 0;
  while(t-- and ++cnt){
    a.clear(), b.clear();
    cin >> in;
    a.resize(in.size()), b.resize(in.size());
    func(in, a, b);
    int idx1 = 0, idx2 = 0;
    while(a[idx1] == '0') idx1++;
    while(idx2 != b.size() - 1 and b[idx2] == '0') idx2++;
    cout << "Case #" << cnt << ": " << a.substr(idx1) << " " << b.substr(idx2) << endl;
  }
}
