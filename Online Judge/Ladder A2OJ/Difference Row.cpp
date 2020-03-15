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

int n, a, c = 2, ans;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--) cin >> a, v.pb(a);
    sort(v.begin(), v.end());
    if(v.size() == 2){
        cout << v.back() << " " << v[0] << endl;
        return 0;
    }

    cout << v.back() << " ";
    for(int i = 1; i < v.size() - 1; i++) cout << v[i] << " ";
    cout << v[0] << endl;
}