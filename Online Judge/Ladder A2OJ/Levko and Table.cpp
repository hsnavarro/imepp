#include<bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            printf("%d%s", i == j ? k : 0, j == n-1 ? "\n" : " ");

    return 0;
}