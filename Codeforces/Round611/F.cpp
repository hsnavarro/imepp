#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, in[N];
vector<int> a;
vector<pair<int, int>> edges;
priority_queue<int> pq;


void add_edge(int a){
  in[a]--;
  int b = -pq.top();
  pq.pop();
  if(!in[a]) pq.push(-a); 
  edges.push_back({a, b});
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  a.resize(n-1);
  for(int i = 0; i < n-1; i++) cin >> a[i], in[a[i]]++;
  for(int i = 1; i <= n; i++) if(!in[i]) pq.push(-i);
  for(int i = n-2; i >= 0; i--) add_edge(a[i]);

  cout << a[0] << "\n";
  for(auto x : edges) 
    cout << x.first << " " << x.second << "\n";
}
