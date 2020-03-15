#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define nd second
#define st first

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5+5;

pii ans, p, ins, sum;
int n, a, b, x[N], y[N];
string s;

bool move(int l, int r){
    int h = r - l + 1;
    int a1 = l ? x[l-1] : 0;
    int a2 = l ? y[l-1] : 0;

    ins.st = ans.st - (p.st - (x[r] - a1));
    ins.nd = ans.nd - (p.nd - (y[r] - a2));

    int a = abs(ins.st) + abs(ins.nd);
    return ((a <= h) and !((a-h)%2));
}

bool test(int x){
    int cond = 0;
    for(int i = 0; i + x <= n; i++)
        if (move(i, i + x - 1)) { cond = 1; break; }
    return cond;
}

int bin(int l, int r){
    while(l != r){
        int mid = (l+r)/2;
        if(test(mid)) r = mid;
        else l = mid+1;
    }
    return l;
}

int main(){
    scanf("%d", &n);
    cin >> s;
    scanf("%d%d", &ans.st, &ans.nd);
    for(int i = 0; i < n; i++){
        if(s[i] == 'U') p.nd++;
        if(s[i] == 'D') p.nd--;
        if(s[i] == 'R') p.st++;
        if(s[i] == 'L') p.st--;
        x[i] = p.st;
        y[i] = p.nd;
    }

    int c = abs(ans.st) + abs(ans.nd);
    if(c > n or ((c-n)%2)) printf("-1\n");
    else {
        int res = bin(0, n + 1);
        printf("%d\n", res == n + 1 ? -1 : res);
    }

    return 0;
}