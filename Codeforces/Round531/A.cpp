#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

ll n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    if(n*(n+1)/2 & 1) cout << 1 << endl;
    else cout << 0 << endl;

}