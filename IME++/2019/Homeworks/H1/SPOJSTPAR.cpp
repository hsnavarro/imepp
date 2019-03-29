#include <bits/stdc++.h>
using namespace std;

int n, idx;
vector<int> v, ans, st;

int main(){
  while(cin >> n and n){
    idx = 1, v.clear(), ans.clear(), st.clear();
    v.resize(n);
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      if(v[i] == idx) ans.push_back(v[i]), idx++;
      else {
        while(st.size() and st.back() == idx) ans.push_back(st.back()), st.pop_back(), idx++;
        st.push_back(v[i]);
      }
    }
    while(st.size())  ans.push_back(st.back()), st.pop_back();
    sort(v.begin(), v.end());
    cout << (v == ans ? "yes" : "no") << endl;
  }
}
