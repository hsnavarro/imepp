#include<bits/stdc++.h>
using namespace std;

int l[] = {4, 7 , 44, 47, 77, 74, 444, 447, 474, 744, 774, 747, 477, 777};
int n, cond;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < 14; i++) if(n % l[i] == 0) { cond = 1; break; }
    printf("%s\n", cond ? "YES" : "NO");

}