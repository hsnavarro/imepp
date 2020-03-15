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

const int N = 1e5+10;

long long t, n, aux, psum[N], sum, idx, pass;


int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld", &aux);
            sum += aux;
            psum[i] = sum;
        }

        idx = psum[0];
        pass = 1;

        while(idx < n-1) {
            idx += psum[idx];
            pass++;
        }

        printf("%lld\n", pass);

    }


    return 0;
}