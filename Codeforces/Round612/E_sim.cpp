#include <bits/stdc++.h>
using namespace std;

string a = "cbaa";

int l, r;
char c;

void query(int l, int r) {
  l--, r--;
  cout << "entered" << endl;
  int sz = (r-l+1);
  vector<string> ans;
  for(int i = 1; i <= sz; i++) {
    for(int j = 0; j <= sz; j++) {
      string ax;
      if(l+j+i > r+1) break;
      for(int k = l+j; k < l+j+i; k++) ax += a[k];
      //cout << ax << endl;
      random_shuffle(ax.begin(), ax.end());
      ans.push_back(ax);    
    }
  }
  random_shuffle(ans.begin(), ans.end());
  for(auto x : ans) cout << x << endl;
}

int main(){
  cout << a.size() << endl; 
  while(true) {
    cin >> c;
    if(c == '!') break;
    else {
      cin >> l >> r;
      query(l, r);
    }
  }
}
