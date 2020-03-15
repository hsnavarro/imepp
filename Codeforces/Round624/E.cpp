#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

const int N = 5e3 + 5;
const int INF = 0x3f3f3f3f;

int t, n, d, lf[N], rt[N], p[N], h[N];
set<pair<int, int>> leaf;
set<int> ht[N];

/*
void print() {
  cout << "## starting print ##" << endl;
  for(int i = 1; i <= n; i++) {
    cout << "node " << i << endl;
    cout << "l, r " << lf[i] << " " << rt[i] << endl;
  }
  cout << "## finishing print ##" << endl;
}
*/

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> d;
    leaf.clear();
    ht[0].clear();
    for(int i = 1; i <= n; i++) ht[i].clear(), lf[i] = rt[i] = p[i] = h[i] = 0;

    ht[0].insert(1);
    for(int i = 1; i+1 <= n; i++) 
      ht[i].insert(i+1), p[i+1] = i, h[i+1] = i, lf[i] = i+1;
    leaf.insert({h[n], n});

    int ans = (n*(n-1))/2;
    if(ans < d) cout << "NO\n";
    else {
      int cond = 1;
      while(ans != d) {
        //print();
        
        int node = -1;
        if(leaf.size()) {
          auto it = leaf.begin();
          node = it->nd;
        }

        if(node == -1) { cond = 0; break; }

        int nxt = -1;
        if(h[node] - 2 < 0) leaf.erase({h[node], node});
        else for(auto x : ht[h[node] - 2]) if(!lf[x] or !rt[x]) { nxt = x; break; }

        leaf.erase({h[node], node});
        if(nxt != -1) {
          if(lf[p[node]] == node) lf[p[node]] = 0;
          else rt[p[node]] = 0;
          if(!lf[p[node]] and !rt[p[node]]) leaf.insert({h[p[node]], p[node]});

          p[node] = nxt;
          if(!lf[nxt]) lf[nxt] = node;
          else rt[nxt] = node;
          ht[h[node]].erase(node);
          h[node] = h[nxt] + 1;
          leaf.insert({h[node], node});
          ht[h[node]].insert(node);
          ans--;
        } 
      }
      if(!cond) cout << "NO\n";
      else {
        cout << "YES\n";
        for(int i = 2; i <= n; i++) cout << p[i] << " ";
        cout << "\n";
      }
    }
  }
}
