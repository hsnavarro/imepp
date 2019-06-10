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

int aux;
string a;

bool check(string a){
    for(int i = 0; i < a.size(); i++) if(a[i] == '0') return true;
    return false;
}

int main(){
    cin >> aux;
    aux++;
    a = to_string(aux);
    while(check(a)){
        int b = stoi(a);
        b++;
        a = to_string(b);
    }
    cout << a << endl;

    return 0;
}