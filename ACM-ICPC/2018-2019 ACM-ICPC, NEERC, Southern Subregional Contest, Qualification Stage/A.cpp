#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

#define st first
#define nd second

int n, m, d, cnt = 1, ans[N];
pair<int, int> a[N];
queue<pair<int, int>> q;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> d;
  for(int i = 0; i < n; i++) cin >> a[i].st, a[i].nd = i;
  sort(a, a + n);
  for(int i = 0; i < n; i++){
   if(q.empty() or q.front().st + d >= a[i].st){
    ans[a[i].nd] = cnt;
    pq.push({a[i].st, cnt++});
   }
   else{
    int aux = q.front().nd; q.pop();
     ans[a[i].nd] = aux;
     pq.push({a[i].st, aux});
   }  
  }
  cout << cnt - 1 << endl;
  for(int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
}
