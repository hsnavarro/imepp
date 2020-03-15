#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 4e5 + 5;

// if all numbers from 1 to k occurs no more than a times 
// we can build the rectangle a*b = k

int n, a, mx;
unordered_map<int, int> freq;
vector<int> v;

void mount(){
  // O(n)
  queue<pair<int, int>> q;
  for(auto x : freq) q.push({x.st, x.nd});
  while(q.size()){
    pair<int, int> ax = q.front();
    q.pop();
    v.push_back(ax.st);
    if(ax.nd > 1) q.push({ax.st, ax.nd-1});
  }
}

void show(int line, int col){
  // O(n log n)
  vector<vector<int>> ans(line, vector<int> (col));
  vector<int> use;

  freq.clear();
  for(int i = 0; i < line*col; i++) freq[v[i]]++;

  for(int i = 0; i < line*col; i++) use.pb(v[i]);
  sort(use.begin(), use.end(), [](int a, int b) { return freq[a] != freq[b] ? freq[a] > freq[b] : a < b; });
 
  int i = 0, j = 0, cnt = 0;
  for(auto x : use) {
    ans[i][j] = x;
    i++, j++;
    j = j%col;
    if(i == line) i = 0, j = (++cnt)%col;
  }

  for(auto x : ans){
    for(auto z : x) printf("%d ", z);
    printf("\n");
  }

}

int find_max_div(int n){
  int resp;
  for(int i = 1; i*i <= n; i++) if(n % i == 0) resp = i;
  return resp;
}

int find_ans(){
  // O(n (log n + sqrt(n)) )
  freq.clear();
  int mx_freq = 0, resp = 0;
  for(int i = 0; i < v.size(); i++){
    freq[v[i]]++;
    mx_freq = max(mx_freq, freq[v[i]]);
    if(mx_freq <= find_max_div(i+1)) resp = max(resp, i+1);
  }
  return resp;
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a), freq[a]++;
  mount();
  for(auto x : v) cout << x << " ";
  cout << endl;
  int ans = find_ans(), k = find_max_div(ans);
  printf("%d\n", ans);
  printf("%d %d\n", k, ans/k);
  show(k, ans/k);
}
