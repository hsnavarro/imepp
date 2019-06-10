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

int n, k;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for(int i = k + 1; i >= 1; i--) cout << i << " ";
    for(int i = k + 2; i <= n; i++) cout << i << " ";
}