#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

#define cl(x, v) memset((x), (v), sizeof(x))
#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;

const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;

struct min_queue{
    vector<pii> s1, s2;

    int size(){ return s1.size() + s2.size(); }

    int mini(){
        if(s1.empty() or s2.empty()) return s1.empty() ? s2.back().nd : s1.back().nd;
        return min(s1.back().nd, s2.back().nd);
    }

    void add(int x){
        int mn = s1.empty() ? x : min(s1.back().nd, x);
        s1.pb({x, mn});
    }

    void rem(){
        if(s2.empty()){
            while(s1.size()){
                int x = s1.back().st; s1.pop_back();
                int mn = s2.empty() ? x : min(x, s2.back().nd);
                s2.pb({x, mn});
            }
        }
        s2.pop_back();
    }

};

int n, t, pr[N], v[N];

bool safe(int r){
    int dp[N];
    min_queue f;
    cl(dp, INF);

    dp[1] = 0;
    f.add(dp[1]);
    for(int i = 2; i <= n; i++){
        if(f.size() > r) f.rem();
        dp[i] = min(dp[i], f.mini()) + v[i];
        f.add(dp[i]);
    }
    return dp[n] <= t;
}

int bin_search(int l = 1, int r = n - 1){
    int mid;
    while(l < r){
        mid = (l+r)/2;
        if(safe(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifstream cin("journey.in");
    ofstream cout("journey.out");
    cin >> n >> t;
    t -= n - 1;
    for(int i = 1; i <= n - 1; i++) cin >> pr[i];
    for(int i = 2; i <= n - 1; i++) cin >> v[i];
    int mn = INF;
    for(int i = bin_search(); i < n; i++) mn = min(mn, pr[i]);
    cout << mn << endl;
}