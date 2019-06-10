#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

string s, res;

bool check1(int i){
    return s[i] == '1';
}

bool check14(int i){
    if(i + 1 >= s.size()) return false;
    return s[i] == '1' and s[i+1] == '4';
}

bool check144(int i){
    if(i + 2 >= s.size()) return false;
    return s[i] == '1' and s[i+1] == '4' and s[i+2] == '4';
}

int main(){
    cin >> s;
    for(int i = 0; i < s.size();){
        if(check144(i)) i += 3;
        else if(check14(i)) i += 2;
        else if(check1(i)) i++;
        else { printf("NO\n"); return 0; }
    }

    printf("YES\n");

    return 0;
}