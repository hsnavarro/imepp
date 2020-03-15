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
const int M = 2e5 + 5;
const int N = 5e5 + 5;


string s, cp;

int main(){
    cin >> s;
    for(int i = 0; i < 5; i++) {
        cin >> cp;
        if(s[0] == cp[0] or s[1] == cp[1]) { printf("YES\n"); return 0; }
    }
    printf("NO\n");
    return 0;
}