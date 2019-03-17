#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

const int N = 5e5 + 5;
const int A = 26;

int n, m, esc, cnt, trie[N][A], triend[N], triecnt[N], trief = 1;
string k, aux;
vector<string> words;
map<char, char> mp, mpa;

int add(int u, int c){
    c -= 'A';
    if(trie[u][c]) return trie[u][c];
    return trie[u][c] = ++trief;
}

bool check_pre(string s){
    int u = 1;
    for(auto c : s){
        c -= 'A';
        if(trie[u][c] and triecnt[trie[u][c]]) u = trie[u][c];
        else return false;
    }
    return true;
}

void trie_add(string s){
    words.push_back(s);
    int u = 1;
    for(auto c : s) u = add(u, c), triecnt[u]++;
    triend[u] = 1;
}

string crip(string s){
    for(int i = 0; i < s.size(); i++) s[i] = mpa[s[i]];
    return s;
}

void op2(){
    cnt++;
    if(cnt == 1) return;
    string aux = crip(k);
    for(int i = 0; i < aux.size(); i++) mpa[k[i]] = mp[aux[i]];
    k = crip(k);
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k.size(); i++) mp[k[i]] = char('A' + i);
    mpa = mp;

    while(m--){
        cin >> esc;
        if(esc == 1) cin >> aux, trie_add(cnt ? crip(aux) : aux);
        if(esc == 2) op2();
        if(esc == 3) cin >> aux, cout << (check_pre(cnt ? crip(aux) : aux) ? "YES" : "NO") << endl;
    }
}