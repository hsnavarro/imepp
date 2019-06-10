#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

ll p, u, res, cont, n, num[105];

int main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &num[i]);

    for(int i = 0; i < n; i++){
        cont = 0;
        while(num[i+1] == num[i] + 1 and i+1 != n){
            if(!cont) p = num[i];
            cont++;
            i++;
        }
        cont++;
        u = num[i];
        if(u != 1000) cont--;
        if(p != 1) cont--;
        res = max(res, cont);
    }

    printf("%lld\n", res);

    return 0;
}