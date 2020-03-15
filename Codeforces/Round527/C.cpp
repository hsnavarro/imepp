#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 105;

int n;
vector<string> ori, comp, s, sh, lo;
string aux, p;
bool ok[N];

void build(string a){
    comp.clear();
    for(int i = 1; i <= a.size() - 1; i++) comp.pb(a.substr(0,i)), comp.pb(a.substr(a.size() - i,i));
    sort(comp.begin(), comp.end());
}

bool check(int w, int h){
    string a = lo[w] + sh[h];
    build(a);
    for(int k = 0; k < 2*n-2; k++) if(s[k] != comp[k]) return false;
    return true;
}

bool is_sufix(string a, string b){
    for(int i = 0; i < b.size(); i++) if(a[a.size() - i - 1] != b[b.size() - i - 1]) return false;
    return true;
}

bool is_prefix(string a, string b){
    for(int i = 0; i < b.size(); i++) if(a[i] != b[i]) return false;
    return true;
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < 2*n-2; i++){
        cin >> aux;
        if(aux.length() == 1) sh.pb(aux);
        if(aux.length() == n - 1) lo.pb(aux);
        ori.pb(aux), s.pb(aux);
    }

    sort(s.begin(), s.end());

    for(int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (check(i, j)) { p = lo[i] + sh[j]; break; }

    for(auto x : ori)
        if(is_prefix(p, x) and !ok[x.size()]) printf("P"), ok[x.size()] = 1;
        else if(is_sufix(p, x)) printf("S");

}