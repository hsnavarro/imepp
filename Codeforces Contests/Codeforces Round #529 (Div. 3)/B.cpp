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

int n, m;
vector<int> v;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &m), v.pb(m);
    sort(v.begin(), v.end());
    m = min(v[n-2] - v[0], v[n-1] - v[1]);
    printf("%d\n", m);
}