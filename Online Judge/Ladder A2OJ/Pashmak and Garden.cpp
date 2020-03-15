#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

int a1, b1, a2, b2, a3, b3, a4, b4;

bool check(int x){
    if(abs(x) <= 1000) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> a1 >> b1 >> a2 >> b2;
    if (a1 != a2 and b1 != b2 and abs(a2 - a1) != abs(b2 - b1)) {
        cout << -1 << endl;
        return 0;
    }
    int sf = max(abs(a2 - a1), abs(b2 - b1));

    if (a1 == a2) {
        if (check(a1 + sf)) a3 = a1 + sf, b3 = b1, a4 = a1 + sf, b4 = b2;
        else if (check(a1 - sf)) a3 = a1 - sf, b3 = b1, a4 = a1 - sf, b4 = b2;
        else {
            cout << -1 << endl;
            return 0;
        }
    } else if (b1 == b2) {
        if (check(b1 + sf)) b3 = b1 + sf, a3 = a1, b4 = b1 + sf, a4 = a2;
        else if (check(b1 - sf)) b3 = b1 - sf, a3 = a1, b4 = b1 - sf, a4 = a2;
        else {
            cout << -1 << endl;
            return 0;
        }
    } else a3 = a1, b3 = b2, a4 = a2, b4 = b1;

    cout << a3 << " " << b3 << " " << a4 << " " << b4 << endl;
}