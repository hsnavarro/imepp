//
// Created by Henrique Navarro on 08/09/2018.
//


#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 3e5 + 5;
const int INF = 0x3f3f3f3f;

int n, l[N], r[N], lst, lnd, rst, rnd, ans;
map<int, int> con;

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d%d", &l[i], &r[i]);
        con.insert({l[i],r[i]});
    }

    sort(l, l + n);
    sort(r, r + n);

    lst = l[n-1];
    lnd = l[n-2];
    rst = r[0];
    rnd = r[1];

    if(con[lst] == rst) ans = rnd - lnd;
    else ans = max(rst - lnd, rnd - lst);

    if(ans <= 0) ans = 0;

    printf("%d\n", ans);





    return 0;
}