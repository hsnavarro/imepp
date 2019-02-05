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

string s, ans;
int n, p, sz, k, n_, p_;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    cin >> k;
    for(auto x : s) {
        if(x == '?') n++;
        else if(x == '*') p++;
        else sz++;
    }

    if(sz == k) {
        for(auto x : s){
            if(x != '*' and x != '?') ans.pb(x);
        }
        cout << ans << endl;
        return 0;
    }
    if(sz - n - p > k) { printf("Impossible\n"); return 0; }
    if(sz < k and p == 0) { printf("Impossible\n"); return 0; }
    if(sz < k and p) {
        p = k - sz;
        for(int i = 0; i < s.size(); i++){
            if(i + 1 < s.size() and s[i+1] == '*') while(p) ans.pb(s[i]), p--;

            if(s[i] != '*' and s[i] != '?') ans.pb(s[i]);
        }
        cout << ans << endl;
        //db(ans.size());
        return 0;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= p; j++){
            if(sz - i - j == k){
                n = -i;
                p = -j;
                for(int k = 0; k < s.size(); k++){
                    if(k + 1 < s.size() and s[k+1] == '*' and p < 0) p++, k++;
                    else if(k + 1 < s.size() and s[k+1] == '?' and n < 0) n++, k++;

                    if(s[k] != '*' and s[k] != '?') ans.pb(s[k]);
                }
                cout << ans << endl;
                return 0;
            }
        }
    }




}