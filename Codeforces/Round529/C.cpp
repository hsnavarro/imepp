#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 1e6 + 5;

int n, k, cnt;
vector<int> f, res, st;

print(vector<int> &a){
printf("YES\n");
for(auto x : a) printf("%d ", x);
printf("\n");
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < 31; i++) if(n & (1 << i)) f.pb(1 << i);

    if(f.size() > k) printf("NO\n");
    else if(f.size() == k) print(f);
    else {
        for (auto x : f) (x == 1) ? res.pb(x) : st.pb(x);

        while (st.size()) {
            n = st.back(), st.pop_back();
            n /= 2, cnt++;
            if (n == 1) res.pb(n), res.pb(n);
            else st.pb(n), st.pb(n);
            if (f.size() + cnt == k) {
                while (st.size()) res.pb(st.back()), st.pop_back();
                break;
            }
        }

        if (res.size() == k) print(res);
        else printf("NO\n");
    }
}