#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, t;
string s, aux;

int main(){
    scanf("%d", &n);
    while(n--) {
        cin >> s;

        if (s.size() > 10) {
            printf("%c", s[0]);
            printf("%d", s.size()-2);
            printf("%c\n", s[s.size()-1]);
        }
        else cout << s << endl;
    }

    return 0;
}