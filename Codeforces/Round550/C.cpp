#include <bits/stdc++.h>
using namespace std;

int n, a;
set<int> c, d;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(c.count(a) and d.count(a)) return cout << "NO" << endl, 0;
    if(!d.count(a))  d.insert(a);
    else c.insert(a);
  }
  cout << "YES" << endl;
  
  cout << c.size() << endl;
  for(auto it = c.begin(); it != c.end(); it++) cout << *it << " ";
  cout << endl;

  cout << d.size() << endl;
  for(auto it = d.rbegin(); it != d.rend(); it++) cout << *it << " ";
  cout << endl;
}
