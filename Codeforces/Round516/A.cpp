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

int v[3];

int main(){
    scanf("%d%d%d", &v[0], &v[1], &v[2]);
    sort(v, v+3);
    int ans = v[2]+1 - (v[0]+v[1]);
    if(ans < 0) ans = 0;

    printf("%d\n", ans);

    return 0;
}