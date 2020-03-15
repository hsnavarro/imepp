#include <bits/stdc++.h>
using namespace std;

string aux;

bool isPalin(string s){
    for(int i = 0; i < s.size()/2; i++) if(s[i] != s[s.size() - 1 - i]) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> aux;
    int cond = 0;
    for(int i = 1; i < aux.size()/2; i++) if(aux[i] != aux[0]) cond = 1;
    if(!cond) cout << "Impossible" << endl;
    else{
        for(int i = 0; i < aux.size(); i++){
            string s = aux.substr(i, aux.size()) + aux.substr(0, i);
            if(s != aux and isPalin(s)) {
                cout << 1 << endl;
                return 0;
            }
        }
        cout << 2 << endl;
        return 0;
    }
}