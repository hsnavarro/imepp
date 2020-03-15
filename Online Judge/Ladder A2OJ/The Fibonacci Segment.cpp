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

int n, a, c = 2, ans;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--) cin >> a, v.pb(a);
    if(v.size() == 1) { cout << 1 << endl; return 0; }
    for(int i = 2; i < v.size(); i++){
        if(v[i] == v[i-1] + v[i-2]) c++;
        else ans = max(ans, c), c = 2;
    }

    cout << max(2, max(ans, c)) << endl;
}