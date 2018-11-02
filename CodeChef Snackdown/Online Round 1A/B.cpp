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

const int N = 1e5 + 5;

int t, n, idx, cond, cont;
int v[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        cl(v, 0);
        cond = 1;
        for(int i = 0; i < n; i++) scanf("%d", &v[i]);

        for(int i = 0; i < n-1; i++) {
            if(v[i] > v[i+1]) {idx = i+1; break;}
            if(i == n-2) {printf("YES\n"); return 0;}
        }



        cont = 0;
        while(idx != n-1){
            if(v[idx] > v[idx+1]) {printf("NO\n"); return 0;}
            idx++;
            cont++;
        }

        if(v[n-1] > v[0]) {printf("NO\n"); return 0;}
        cont++;
        idx = 0;
        if(cond) {
            while (cont != n - 1) {
                if(v[idx] > v[idx+1]) {cond = 0; break;}
                idx++, cont++;
            }
        }

        printf("%s\n", cond ? "YES" : "NO");
    }
    return 0;
}