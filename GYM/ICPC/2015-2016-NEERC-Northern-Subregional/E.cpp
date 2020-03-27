#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

string s, res;
int cond;

bool isnum(char a) { return (a != '+' and a != '-'); }

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifstream cin("easy.in");
    ofstream cout("easy.out");
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        res += s[i];
        if(i + 2 < n and s[i] == '-' and isnum(s[i+1]) and isnum(s[i+2])){
            res += s[i+1];
            res += '+';
            cond = 1;
            i++;
        }

        if(cond){
            while(i + 1 < n-1 and s[i+1] == '0') {
                res += s[i+1];
                if(i + 2 < n and isnum(s[i+2])) res += '+';
                i++;
            }
            cond = 0;
        }
    }
    cout << res << endl;
}