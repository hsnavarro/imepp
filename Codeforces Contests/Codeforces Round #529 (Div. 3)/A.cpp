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

int n, m, k;
string s, res;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    for(int i = 0, k = 1; i < s.size(); i += k) res += s[i], k++;
    cout << res << endl;
}