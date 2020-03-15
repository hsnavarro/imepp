#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> pii;


const int N = 2e5 + 5;

int n, in[N], out[N], to[N];
vector<int> iso, rec, pnt;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> to[i];
    if(to[i]) in[to[i]]++, out[i]++;
  }

  for(int i = 1; i <= n; i++){
    if(!in[i] and !out[i]) iso.pb(i);
    if(!in[i] and out[i]) rec.pb(i);
    if(in[i] and !out[i]) pnt.pb(i);
  }

  for(int i = 0; i+1 < iso.size(); i++) to[iso[i]] = iso[i+1];
  int cnt = 0;
  if(iso.size()) rec.pb(iso[0]), to[iso.back()] = rec[cnt++];
  for(auto x : pnt) to[x] = rec[cnt++];

  for(int i = 1; i <= n; i++) cout << to[i] << " ";
  cout << "\n";
}
