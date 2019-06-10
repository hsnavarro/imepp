#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 1e6 + 5;

int w, h, w1, w2, h1, h2;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> w >> h;
    cin >> w1 >> h1;
    cin >> w2 >> h2;

    while(h){
        w += h;
        if(h == h1) w = max(0, w - w1);
        if(h == h2) w = max(0, w - w2);
        h--;
    }

    cout << w << endl;

}