#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back

const int N = 5e5 + 5;

int n, x, y, w, h, mx_x, mx_y;
char esc;

// x > y
// w > h

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--){
        cin >> esc >> x >> y;
        if(y > x) swap(x, y);
        if(esc == '+') mx_x = max(mx_x, x), mx_y = max(mx_y, y);
        else{
            if(y >= mx_y and x >= mx_x) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}