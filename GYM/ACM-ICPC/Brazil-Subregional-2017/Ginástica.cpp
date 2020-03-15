//
// Created by Henrique Navarro on 10/09/2018.
//

#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5+5;
const int M = 50+5;

int t, m, n, res = 0;
int dp[N][M];

int dpcalc (int i, int j){
    if(dp[i][j] != -1) return dp[i][j];

    if(j == t) dp[i][j] = 1;
    else if(i == n) dp[i][j] = dpcalc(i-1,j+1)%MOD;
    else if(i == m) dp[i][j] = dpcalc(i+1,j+1)%MOD;
    else dp[i][j] = dpcalc(i-1, j+1)%MOD + dpcalc(i+1, j+1)%MOD;

    return dp[i][j];
}


int main(){
    scanf("%d%d%d", &t, &m, &n);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
           dp[i][j] = -1;
        }
    }

    for(int i = m; i <= n; i++){
        res += dpcalc(i,1)%MOD;
        res = res%MOD;
    }

    printf("%d\n", res);

    return 0;
}