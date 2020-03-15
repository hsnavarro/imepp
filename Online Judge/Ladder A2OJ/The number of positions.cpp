#include<bits/stdc++.h>
using namespace std;

int n, a, b, cnt;

int main(){
    scanf("%d%d%d", &n, &a, &b);
    printf("%d\n", min(b+1, n-a));

    return 0;
}