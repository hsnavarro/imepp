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

int t, n, k, aux, ans;
vector<int> s;



int main(){
    cin >> t;
    while(t--){
        s.clear();
        ans = 0;
        cin >> n >> k;

        for(int i = 0; i < n; i++){
            cin >> aux;
            s.pb(aux);
        }
        sort(s.begin(), s.end());
        int idx = n-k;
        int cont = idx - 1;
        while(s[idx] == s[cont]){
            cont--;
            ans++;
        }
        cout << ans+k << endl;
    }

    return 0;
}