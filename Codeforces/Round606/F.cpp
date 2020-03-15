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

int n, a, mx, sum[N], occ[N];
vector<int> aux[N];
unordered_map<int, int> freq;

void show(int line, int col){
  printf("%d\n", line*col);
  printf("%d %d\n", line, col);
  vector<vector<int>> ans(line, vector<int> (col));
  
  for(auto x : freq) aux[x.nd].push_back(x.st);
  int i = 0, j = 0, cnt = 0;
  for(int f = n; f >= 1; f--)
    for(auto x : aux[f])
      for(int k = 0; k < min(f, line); k++){
        if(!cnt or i or j) ans[i][j] = x, i++, j = (j+1)%col;
        if(i == line) i = 0, j = (++cnt)%col;
      }

  for(auto x : ans){
    for(auto z : x) printf("%d ", z);
    printf("\n");
  }
}

void go(){
  int resp = 0, line = 0;
  for(auto x : freq) sum[x.nd] += x.nd, occ[x.nd]++;
  for(int i = 1; i <= n; i++) sum[i] += sum[i-1], occ[i] += occ[i-1];

  for(int side = 1; side*side <= n; side++){
    int b = sum[side]/side + occ[n] - occ[side];
    if(b >= side and side*b > resp) resp = side*b, line = side;
  }
  show(line, resp/line);
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a), freq[a]++;
  go();
}
