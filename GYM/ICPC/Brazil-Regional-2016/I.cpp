#include<bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 6e3+5;
int n , b , c , A[N] , dp[N][N] , custo1[N] , custo2[N] , sm1[N] , sm2[N];

int cst(int x , int y){
  
  if(y > x) return inf;
  if(x == y) return 0;
  if(dp[x][y] != inf) return dp[x][y];

  for(int i = 1 ; i <= x-1 ; i++){
    int mid = (x-i)/2+i;
    if( (x-i)%2 == 0){
      int cst1 = cst(i,y-1)+custo1[x]-custo1[mid]-sm1[mid-1]*(x-mid)+custo2[i]-custo2[mid+1]-sm2[mid]*(mid-i+1);
      dp[x][y] = min(cst1,dp[x][y]);
    }
    else{
      int cst1 = cst(i,y-1)+custo1[x]-custo1[mid+1]-sm1[mid]*(x-mid)+custo2[i]-custo2[mid]-sm2[mid+1]*(mid-i+1);
      dp[x][y] = min(cst1,dp[x][y]);
    }
  }

  return dp[x][y];

}

int32_t main(){

  while(cin >> n >> b >> c){
    
    for(int i = 0 ; i < N ; i++)
      for(int j = 0 ; j < N ; j++)
        dp[i][j] = inf;

    for(int i = 1 ; i <= n ; i++) cin >> A[i];
    
    for(int i = 1 ; i <= n ; i++){
      sm1[i] = sm1[i-1]+A[i];
      sm2[n-i+1] = sm2[n-i+2]+A[n-i+1];
    }
  
    cout << "custo:\n";
    for(int i = 1 ; i <= n ; i++){
      custo1[i+1] = custo1[i]+sm1[i];
      custo2[n-i] = custo2[n-i+1]+sm2[n-i+1];
      dp[i][1] = custo1[i]+custo2[i];
    }
    
    for(int i = 1 ; i <= n ; i++){
      cout << custo1[i] << " " << custo2[i] << "\n";
    }
    
    cout << "sm:\n";
    for(int i = 0 ; i <= n ; i++)
      cout << sm1[i] << " " << sm2[i] << "\n";

    for(int i = 1 ; i <= n ; i++){
    int k = cst(n,i);
      cout << k << " ";
    }
    cout << "\n";

  }

}
