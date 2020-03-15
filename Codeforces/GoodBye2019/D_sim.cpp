#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int INF = 0x3f3f3f3f;

int n, k, m, x;
set<int> s;
vector<int> v;
vector<pair<int, int>> inp;
char a;

void generate(){
  while(v.size() != n) {
    int ax = rand();
    if(!s.count(ax)) {
      v.push_back(ax);
      s.insert(ax);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> m;
  v = {2, 0, 1, 9};
  //generate();
  while(true){
    inp.clear();
    cin >> a;
    if(a == '!') {
      cin >> x;
      cout << x << endl;
      break;
    } else {
      for(int j = 0; j < k; j++) 
        cin >> x, inp.push_back({v[x-1], x});

      sort(inp.begin(), inp.end());
      cout << inp[m-1].second << " " << inp[m-1].first << endl;
    }
  }
}
