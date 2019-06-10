#include<bits/stdc++.h>
using namespace std;

string s, ans;

bool isvowel(char a){
    if(a == 'a' or a == 'A') return true;
    if(a == 'o' or a == 'O') return true;
    if(a == 'y' or a == 'Y') return true;
    if(a == 'e' or a == 'E') return true;
    if(a == 'u' or a == 'U') return true;
    if(a == 'i' or a == 'I') return true;
    return false;
}

bool islower(char a){
    if(a >= 'a' and a <= 'z') return true;
    return false;
}

int main(){
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(!isvowel(s[i])){
            ans.push_back('.');
            if(!islower(s[i])) ans.push_back(s[i] + - 'A' + 'a');
            else ans.push_back(s[i]);
        }
    }

    cout << ans << endl;

    return 0;
}
