#include<bits/stdc++.h>
using namespace std;

int n;

void spc(int n){
    for(int i = 0; i < n; i++) printf("  ");
}

void print(int n){
    for(int i = 0; i <= n; i++){
        spc(n-i);
        for(int j = 0; j <= i; j++) printf("%d%s", j, i == 0 ? "" : " ");
        for(int j = i-1; j >= 0; j--) printf("%d%s", j, j == 0 ? "" : " ");
        printf("\n");
    }
    for(int i = n-1; i >= 0; i--){
        spc(n-i);
        for(int j = 0; j <= i; j++) printf("%d%s", j, i == 0 ? "" : " ");
        for(int j = i-1; j >= 0; j--) printf("%d%s",j,  j == 0 ? "" : " ");
        printf("\n");
    }
}

int main(){
    scanf("%d", &n);
    print(n);

    return 0;
}