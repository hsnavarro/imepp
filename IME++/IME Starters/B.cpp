#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 1e3 + 5;

int kit, m, n, w[105], aux;
pair<string, int> obj[N];
string s;
int dp[N][2*N];
vector<string> res;

void ans(int i, int j){
    if(!i) {
        printf("%d ", res.size());
        for(auto x : res) cout << x << " ";
        res.clear();
        printf("\n");
        return;
    }
    if(j - obj[i].nd >= 0 and dp[i - 1][j - obj[i].nd] == dp[i][j]) res.pb(obj[i].st), ans(i - 1, j - obj[i].nd);
    else ans(i - 1, j);
}

int teto(int a, int b){return (a+b-1)/b; }

int main(){
    scanf("%d%d", &kit, &m);
    for(int i = 1; i <= m; i++) {
        cin >> s >> aux;
        obj[i] = {s, aux};
    }

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]), w[i] = max(teto(w[i], 2) - kit, 0);

    dp[0][0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < 2*N; j++){
            if(j - obj[i].nd < 0) dp[i][j] = dp[i-1][j];
            else  dp[i][j] = max(dp[i-1][j], dp[i-1][j-obj[i].nd]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = w[i]; j < 2*N; j++){
            if(dp[m][j]) { ans(m, j); break; }
            if(j == 2*N-1) printf("-1\n");
        }
    }
}