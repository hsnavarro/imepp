#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int n, freq[500], ult, penu, res, freq_x, cont;
char alf[300];
char c_ult, c_penu;
string s;
vector<string> v;
set<char> aux;


int main(){
    cin >> n;
    while(n--){
        cin >> s;
        aux.clear();
        for(auto x : s) aux.insert(x);
        if(aux.size() <= 2) v.pb(s);
    }

    for(int i = 'a'; i <= 'z'; i++) alf[i - 'a'] = i;

    for(int i = 0; i <= 30; i++){
        for(int j = 0; j <= 30; j++){
            res = max(res, cont);
            cont = 0;
            for(auto x : v){
                int ok = 1;
                for(auto p : x) {
                    if(p != alf[i] and p != alf[j]) {ok = 0; break;}
                }
                if(ok) cont += x.size();
            }
        }
    }

    cout << max(res, cont) << endl;



    +
}