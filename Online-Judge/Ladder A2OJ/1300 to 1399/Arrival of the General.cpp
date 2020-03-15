#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int n, v[N], mx = -INF, mn = INF, i_mx, i_mn, ans;

void update() {
    int cond = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == mx and !cond) {i_mx = i; cond++;}
        if (v[i] == mn) i_mn = i;
    }
}

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);

    for (int i = 0; i < n; i++) {
        if (v[i] > mx) { mx = v[i], i_mx = i; }
        if (v[i] <= mn) { mn = v[i], i_mn = i; }
    }

    while(i_mx){
        swap(v[i_mx-1], v[i_mx]);
        update();
        ans++;
    }
    while(i_mn != n-1){
        swap(v[i_mn+1], v[i_mn]);
        update();
        ans++;
    }


    printf("%d\n", ans);










    return 0;
}