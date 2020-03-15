#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
//a/x - a + b*x - b < 0

int n, b, mn = 0x3f3f3f3f, s;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int a;
    while(n--) cin >> a, s += a, v.push_back(a);

    sort(v.begin(), v.end());
    b = v[0];


    for(int i = v.size() - 1; i > 0; i--){
        a = v[i];
        for(int x = 1; x <= a; x++){
            if(a % x == 0){
                mn = min(mn, a/x - a + b*x - b);
            }
        }
    }

    cout << s + mn << endl;
    return 0;
}