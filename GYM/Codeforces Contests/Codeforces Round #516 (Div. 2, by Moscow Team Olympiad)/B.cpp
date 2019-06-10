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

int n, t, ans;

int setBits(int num) {
    int count = 0;
    while(num != 0) {
        if( (num&1) == 1)
            count++;
        num = num >> 1;
    }
    return count;
}

int fexp (int b, int e) {
    int ans = 1;
    while (e) {
        if (e&1) ans = (ans*b);
        b = (b*b);
        e >>= 1;
    }
    return ans;
}

int main(){
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        ans = fexp(2, setBits(n));
        printf("%d\n", ans);
    }

    return 0;
}