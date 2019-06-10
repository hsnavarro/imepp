#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

int t, n;

bool isprime(int n){
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

bool issemiprime(int n){
    for(int i = 1; i <= n; i++){
        if(isprime(i) and n % i == 0 and (n/i) != i){
            if(isprime(n/i)) return true;
        }
    }
    return false;
}


int main(){
    scanf("%d", &t);

    while(t--){
        int cond = 0;
        scanf("%d", &n);
        for(int i = 0; i <= (n+1)/2; i++){
            if(issemiprime(i) and issemiprime(n-i)) {
                printf("YES\n");
                cond = 1;
                break;
            }
        }
        if(cond == 0) printf("NO\n");
    }

    return 0;
}