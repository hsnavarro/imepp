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

int n, m, ax, bx, mn = 1005;
vector<pii> o, a, b;

bool cmp(pii a, pii b){
    if(b.nd < a.nd) return false;
    if(b.nd == a.nd and b.st < a.st) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--) cin >> ax >> bx, o.pb({ax, bx});
    a = b = o;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), cmp);
    for(int i = 0; i < a.size(); i++) if(a[i] != b[i]) { printf("Happy Alex\n"); return 0; }
    printf("Poor Alex\n");
}