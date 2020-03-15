#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, freq[N], mx, mn;
vector<int> v;
vector< pair<int, pair<int, int>> > rng;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i], freq[v[i]]++;
  int l = 0, sum = 0;
  for(int i = 1; i <= n+1; i++) {
    sum += freq[i];
    if(!l and freq[i]) l = i;
    if(l and !freq[i]) rng.pb({sum, {l, i-1}}), l = 0, sum = 0;
  }
  
  // max
  for(int i = 0; i < rng.size(); i++){
    int left = 0, right = 0;
    int l = rng[i].nd.st, r = rng[i].nd.nd, s = rng[i].st, cnt = (s-(r-l+1));
    if(!cnt) continue;

    if(!i or l - rng[i-1].nd.nd >= 2) left = 1;
    if(i == rng.size() - 1 or rng[i+1].nd.st - r >= 2) right = 1;

    if(cnt == 1) {
      if(left) rng[i].nd.st--;
      else if(right) rng[i].nd.nd++;
    } else {
      if(left) rng[i].nd.st--;
      if(right) rng[i].nd.nd++;
    }
  }

  for(auto x : rng) mx += x.nd.nd - x.nd.st + 1;

  // min
  for(int i = 1; i <= n; i++) if(freq[i]) i += 2, mn++;

  cout << mn << " " << mx << "\n";
}
