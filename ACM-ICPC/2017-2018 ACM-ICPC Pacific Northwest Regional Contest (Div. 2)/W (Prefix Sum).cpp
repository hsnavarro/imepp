#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 30 + 5;

int n, m;
int minr[N], maxb[N];
char table[N][N];
string s;
ll dp[N][N];

bool in (int i, int j) { return !(j < maxb[i] or j >= minr[i]); }

int main(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < N; i++) minr[i] = m + 1;

    for(int i = 1; i <= m; i++){
        cin >> s;
        for(int j = 1; j <= n; j++){
            table[i][j] = s[j-1];
            if(table[i][j] == 'B') maxb[j] = max(maxb[j], i);
            if(table[i][j] == 'R') minr[j] = min(minr[j], i);
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            if(i == 1) dp[1][j] += (in(i, j) ? 1 : 0) + (j == maxb[1] ? 0 : dp[1][j-1]);
            else dp[i][j] += (in(i, j) ? dp[i-1][m] - dp[i-1][j-1] : 0) + (j == maxb[i] ? 0 : dp[i][j-1]);

    printf("%lld\n", dp[n][m]);
}