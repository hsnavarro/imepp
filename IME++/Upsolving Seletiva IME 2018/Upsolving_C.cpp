//
// Created by Henrique Navarro on 08/08/2018.
//
#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

const int N = 1e6 + 5;
const int X = 1e9;
const int MOD = 1e9 + 7;


int col[10], lin[10], block[10][10], reg[40];

bool test(int l, int c, int k){
    if(c > 5) return false;
    if(l > 5) return false;
    if(k > 6 or k < 1) return false;
    if((col[c] | lin[l]  | block[l/2][c/3] | reg[grid[l][c]] ) & (1<<k)){
        return false;
    }
    if( )
        //v[grid[l][c]] => valor naquele grid

    return true;
}

int n, v[40], grid[10][10];

int main(){

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }

    for(int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            scanf("%d", &grid[i][j]);
        }
    }



    if(add(1,1,1)){
        add(l,c+1,k+1);
    }

    return 0;
}