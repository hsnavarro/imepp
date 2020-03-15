#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

string s, res;

bool check(int i){
    if(i + 2 >= s.size()) return false;
    return s[i] == 'W' and s[i+1] == 'U' and s[i+2] == 'B';
}

int main(){
    cin >> s;
    for(int i = 0; i < s.size();){
        if(check(i)) i += 3;
        else{
            while(!check(i) and i < s.size()) { res += s[i]; i++; }
            res += " ";
        }
    }

    cout << res << endl;

    return 0;
}