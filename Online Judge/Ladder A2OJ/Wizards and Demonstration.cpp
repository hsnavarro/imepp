#include<bits/stdc++.h>
using namespace std;

int n, x, y;

int main(){
    scanf("%d%d%d", &n, &x, &y);
    for(int i = 0; i < 2e8; i++)
        if((x+i)*100/n >= y){ printf("%d\n", i); return 0; }

    return 0;
}