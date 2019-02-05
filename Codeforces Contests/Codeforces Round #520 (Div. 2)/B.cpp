#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

typedef long long ll;

int n, aux, mn = 1, ans;

ll fexp (int b, int e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b);
        b = (b*b);
        e >>= 1;
    }
    return ans;
}

void factor(int n) {
    for (int i = 2; i <= n; i++){
        if(n%i == 0) mn *= i;
        while(n%i == 0) n /= i;
        if(i == 1) break;
    }
}

int main(){
    scanf("%d", &n);
    factor(n);
    if(mn == n) {printf("%d 0\n", mn); return 0; }
    for (int i = 1; i < n; i++) {
        if (fexp(mn, 1<<i) % n == 0){
            if(fexp(mn, 1<<i) / n == 1) ans = i;
            else ans = i+1;

            break;
        }
    }

    printf("%d %d\n", mn, ans);

    return 0;
}