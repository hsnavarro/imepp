#include<bits/stdc++.h>
using namespace std;

int n, k, sum;
int main(){
    scanf("%d %d", &n, &k);
    sum = (1+n)*n/2;
    k = (k%sum);
    for(int i = 1; i <= n; i++){
        if(k >= i) k -= i;
        else break;
    }

    printf("%d\n", k);


    return 0;
}