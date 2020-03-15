#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 5e5 + 5;

int n, ans, cnt;
pair<int, int> p[N];
string s;

void check(string s){
    queue<int> q;
    int e = 0, d = 0;
    for(int j = 0; j < s.size(); j++){
        if(s[j] == ')') {
            if(q.empty()) d++;
            else q.pop();
        }
        if(s[j] == '(') q.push(1);
    }
    e = q.size();
    if(!e and !d) {ans++; return;}
    if(e and d) return;
    if(e) p[e].st++;
    if(d) p[d].nd++;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> s;
        check(s);
    }

    for(auto x : p){
        cnt += min(x.st, x.nd);
    }


    printf("%d\n", cnt + ans/2);


}