#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;

int a;
set<pii> res;

int main(){
    cin >> a;

    for(int i = 1; i < a; i++){
        if(a%(i) == 0 and i != 1) res.insert({a/(i), a/(i)});
        if((a-i)%(2*i) == 0 and (a-i)/(2*i) + 1 != a) res.insert({(a-i)/(2*i) + 1, (a-i)/(2*i)});
        if((a-i)%(2*i-1) == 0 and (a-i)/(2*i-1) + 1 != a) res.insert({(a-i)/(2*i-1) + 1, (a-i)/(2*i-1)});
    }

    printf("%d:\n", a);
    for(auto x : res) printf("%d,%d\n", x.st, x.nd);


    return 0;
}