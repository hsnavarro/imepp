#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

string s1, s2;
int ans = 0;

int main() {
    cin >> s1;
    cin >> s2;

    int a, b;

    for(int i = 0; i < s1.size(); i++){
        if(s1[i] >= 'a') a = s1[i] - 'a';
        else a = s1[i] - 'A';
        if(s2[i] >= 'a') b = s2[i] - 'a';
        else b = s2[i] - 'A';
        if(a < b) {printf("-1"); return 0;}
        if(a > b) {printf("1"); return 0;}
    }

    printf("0\n");


    return 0;
}