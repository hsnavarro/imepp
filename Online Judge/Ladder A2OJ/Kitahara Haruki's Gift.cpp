#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

int n, x, y, a, b;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--) cin >> a, a == 200 ? x++ : y++;
    for(int i = 0; i <= x; i++) for(int j = 0; j <= y; j++) if(i*4 + j*2 == 2*x + y) {printf("YES\n"); return 0;}
    printf("NO\n");
}