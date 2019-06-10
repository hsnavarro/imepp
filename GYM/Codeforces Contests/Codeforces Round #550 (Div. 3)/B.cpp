#include <bits/stdc++.h>
using namespace std;

int n, aux, sum;
vector<int> p, imp;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> aux;
    if(aux & 1) imp.push_back(aux);
    else p.push_back(aux);
  }
  sort(imp.begin(), imp.end());
  sort(p.begin(), p.end());

  if(p.size() == imp.size()) return cout << "0" << endl, 0;
  if(p.size() < imp.size()) swap(p, imp);
  for(int i = 0; i < p.size() - imp.size() - 1; i++) sum += p[i];
  cout << sum << endl;
}
