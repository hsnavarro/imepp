#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 5;

int n, cnt, sum;
pair<int, int> p[N], s[N];
string c;

int val(char a){
    if(a == '(') return 1;
    return -1;
}

int main(){
    scanf("%d", &n);
    cin >> c;
    for(int i = 1; i <= n; i++){
        sum += val(c[i-1]);
        if(sum < 0) {
            for(int k = i; k <= n; k++) p[k].st = -1;
            break;
        }
        p[i].st = 1, p[i].nd = sum;
    }
    sum = 0;
    for(int i = n; i >= 1; i--){
        sum -= val(c[i-1]);
        if(sum < 0) {
            for(int k = i; k >= 1; k--) s[k].st = -1;
            break;
        }
        s[i].st = 1, s[i].nd = sum;
    }

    for(int i = 1; i <= n; i++) if(p[i-1].st != -1 and s[i+1].st != -1 and s[i+1].nd - p[i-1].nd + val(c[i-1]) == 0) cnt++;
    printf("%d\n", cnt);
}