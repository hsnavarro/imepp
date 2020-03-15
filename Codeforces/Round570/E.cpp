#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, k;
string s;
set<string> st;

void bfs(){
  queue<string> q;
  q.push(s);
  st.insert(s);
  while(q.size()){
    string aux = q.front();
    q.pop();
    if(st.size() == k) return;
    for(int i = 0; i < aux.size(); i++){
      string n;
      for(int j = 0; j < aux.size(); j++) if(j != i) n += aux[j];
      if(!st.count(n)) {
        st.insert(n);
        if(st.size() == k) return;
        q.push(n);
      }
    }
  }
}



int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> s;
  bfs();
  if(st.size() < k) return cout << -1 << "\n", 0;
  ll sum = 0;
  for(auto x : st) sum += 1ll*(n - x.size());
  cout << sum << "\n";
}
