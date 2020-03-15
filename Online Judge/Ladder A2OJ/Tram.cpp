#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, a, b, sum, mx = -INF;
int main(){
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &a, &b);
        sum -= a;
        sum += b;

        mx = max(mx, sum);
    }

    printf("%d\n", mx);


    return 0;
}