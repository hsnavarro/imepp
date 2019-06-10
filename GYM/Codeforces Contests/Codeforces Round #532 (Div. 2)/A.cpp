#include<bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

const int INF = 0x3f3f3f3f;
const int N = 1e3 + 5;

int n, k, aux, S, E, mx;
vector<int> v;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        (aux == 1) ? E++ : S++;
        v.pb(aux);
    }

    for(int i = 0; i < k; i++){
        int s = S, e = E;
        for(int j = i; j < n; j += k) v[j] == 1 ? e-- : s--;
        mx = max(mx, abs(s-e));
    }

    cout << mx << endl;
}

