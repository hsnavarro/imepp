#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

string a, b;
int per[N];
vector<int> v;

bool test(int idx){
  int k = 0;
  set<int> ok;
  for(int i = 0; i <= idx; i++) ok.insert(per[i]);
  for(int i = 0; i < a.size(); i++) {
    if(ok.count(i+1)) continue;
    if(a[i] == b[k]) k++;
    if(k == b.size()) return true;
  }
  return false;
}

int binsearch(int l, int r){
  int mid;
  while(l != r){
    mid = (l+r)/2;
    if(test(mid)) l = mid+1;
    else r = mid;
  }
  return l;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  for(int i = 1; i <= a.size(); i++) cin >> per[i];
  cout << max(0, binsearch(0, a.size()) - 1) << endl;
}
