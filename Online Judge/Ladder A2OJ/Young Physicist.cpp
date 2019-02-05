#include<bits/stdc++.h>
using namespace std;

int n, x, y, z, a, b, c;

int main(){
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d %d", &a, &b, &c);
        x += a;
        y += b;
        z += c;
    }

    if(!x and !y and !z) printf("YES\n");
    else printf("NO\n");

    return 0;
}