#include<bits/stdc++.h>
using namespace std;

int n, ans, a, b, dp[105][105];
set<int> input;

int mex(set<int> &p){
    for(int i = 0; i <= 1000; i++){
        if(!p.count(i)) return i;
    }
}

int main(){

    for(int L = 0; L <= 100; L++){
        for(int C = 0; C <= 100; C++){
            if(L == 0 or C == 0 or C == L) dp[L][C] = -1;
            else{
                input.clear();
                for(int k = 1; k <= 100; k++){
                    if(L-k >= 0) input.insert(dp[L-k][C]);
                    if(C-k >= 0) input.insert(dp[L][C-k]);
                    if(L-k >= 0 and C-k >= 0) input.insert(dp[L-k][C-k]);
                }
                dp[L][C] = mex(input);
            }
        }
    }

    scanf("%d", &n);
    int cond = 0;
    while(n--){
        scanf("%d%d", &a, &b);
        if(a == 0 or b == 0 or a == b) cond = 1;
        ans = ans^dp[a][b];
    }

    if(cond) printf("Y\n");
    else printf("%s\n", ans ? "Y" : "N");

    return 0;
}


