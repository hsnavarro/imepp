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

string a, aux;

bool is_palin(string s){
    for(int i = 0; i < s.size()/2; i++) if(s[i] != s[s.size()-1-i]) return false;
    return true;
}


int main(){
    cin >> a;
    for(int i = 2; i <= a.size(); i += 2){
        for(int j = 0; j + i < a.size(); j++){
            if(is_palin(a.substr(j, i))){
                printf("Or not.\n");
                return 0;
            }
        }
    }

    printf("Odd.\n");
    return 0;

}