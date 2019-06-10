#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 1e7 + 5;

#define st first
#define nd second

int n, aux, it[M];
pair<int, int> last[M], ans[N];

pair<int, int> find(int x){
  if(last[x].st < last[x].nd){
    swap(last[x].st, last[x].nd);
    return last[x];
  }
  if(it[x] == 1) return it[x]++, last[x] = {1, x};
  
  for(int i = it[x]; i*i <= x; i++)
    if(x % i == 0)  return it[x] = i+1, last[x] = {i, x/i};

  cout << "NO" << endl, exit(0);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < M; i++) it[i] = 1;
  for(int i = 0; i < n; i++) cin >> aux, ans[i] = find(aux);
  cout << "YES" << endl;
  for(int i = 0; i < n; i++) cout << ans[i].st << " " << ans[i].nd << endl;
}

