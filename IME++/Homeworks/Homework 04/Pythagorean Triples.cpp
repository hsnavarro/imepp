#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k;

int main(){

    scanf("%lld", &n);

    if(n&1){
        //x^2 + a^2 = (a+1)^2
        m = (n*n - 1)/2;
        k = m+1;
    }
    else{
        //x^2 + (a-1)^2 = (a+1)^2
        m = (n*n/4) - 1;
        k = m+2;
    }
    if(m and k) printf("%lld %lld\n", m, k);
    else printf("-1\n");


    return 0;
}

