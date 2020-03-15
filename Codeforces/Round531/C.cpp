#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5000 + 5;
int n, d, r, a, cnt;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> d >> r;
    int aux = n;
    while(aux--) {
        cin >> a;
        if(a <= d) cnt++;
    }

    if(d > r) cout << n << endl;
    else cout << (cnt+1)/2 << endl;
}