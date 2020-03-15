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

int t, n, a[N], b[N];

void add (int pos, int k){
    a[pos] += k;
    a[pos+1] += 2*k;
    a[pos+2] += 3*k;
}

int main(){
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) scanf("%d", &b[i]);

        int pos = 0;
        while(pos < n-2){
            if(a[pos] != b[pos]){
                add(pos, b[pos] - a[pos]);
            }
            pos++;
        }

        int cond = 1;
        for(int i = 0; i < n; i++) if(a[i] != b[i]) {cond = 0; break;}

        printf("%s\n", cond ? "TAK" : "NIE");

    }

    return 0;
}

