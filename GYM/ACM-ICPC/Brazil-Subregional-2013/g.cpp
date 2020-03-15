#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int l, c;

pii pos(int x, vector<vector<int>> &M){
  pii resp;
  for(int i=0; i<l; i++)
    for(int j=0; j<c; j++){
      if(M[i][j] == x) resp = {i, j};
    }
  return resp;
}

bool check(vector<vector<int>> &M){
  for(int i=0; i<l; i++)
    for(int j=0; j<c; j++){
      if(M[i][j] != i*c + j +1) return false;
    }
  return true;
}

int32_t main(){
  // ios_base::sync_with_stdio(0), cin.tie(0);
  while(scanf("%d%d", &l, &c) != EOF){
    vector<vector<int>> M(l,vector<int>(c, 0));
    for(int i = 0; i<l; i++){
      for(int j=0; j<c; j++){
        int a;
        scanf("%d", &a);
        M[i][j] = a;
      }
    }
    pii p1 = pos(1, M);
    int ans = 0;
    if(p1.st != 0) swap(M[p1.st], M[0]), ans++;;
    for(int i=1; i<=c; i++){
      pii p = pos(i, M);
      if(p.st == 0 and p.nd == i-1) continue;
      ans++;
      for(int j=0; j<l; j++){
        swap(M[j][p.nd], M[j][i-1]);
      }
    }
    for(int i=2 ; i<=l; i++){
      pii p = pos((i-1)*c+1, M);
      if(p.st == i-1 and p.nd == 0) continue;
      swap(M[p.st], M[i-1]);
      ans++;
    }
    /* for(int i=0; i<l; i++){
       for(int j=0; j<c; j++){
       printf("%d ", M[i][j]);
       }
       printf("\n");
       }*/
    if(check(M)) printf("%d\n", ans);
    else printf("*\n");
  }
}
