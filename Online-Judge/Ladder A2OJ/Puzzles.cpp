#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 1e6 + 5;

int n, m, a, mn = 1005;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    int aux = m;
    while(aux--) cin >> a, v.pb(a);
    sort(v.begin(), v.end());
    for(int i = 0; i + n - 1 < v.size(); i++) mn = min(mn, v[i+n-1] - v[i]);

    cout << mn << endl;
}