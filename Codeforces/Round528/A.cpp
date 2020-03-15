#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back

typedef long long ll;

const int N = 5e5 + 5;
const int A = 26;

string s, res;
int st, k;

int main(){
    cin >> s;
    st = s.size()/2;
    if(!(s.size() & 1)) st--;
    res += s[st];
    while(res.size() != s.size() and ++k){
        res += s[st+k];
        if(res.size() == s.size()) break;
        res += s[st-k];
        if(res.size() == s.size()) break;
    }

    cout << res << endl;
}