#include<bits/stdc++.h>
using namespace std;

int t, a;
set<int> v;

void ans(){ for(int i = 3; i <= 2e5; i++) if(!(((i-2)*180)%i)) v.insert((i-2)*180/i); }

int main(){
    ans();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &a);
        if(v.count(a)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}