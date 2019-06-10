#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 1e6 + 5;

int n, m, a, mn = 1005;
set<int> s;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--) cin >> a, s.insert(a);
    for(int i = 1; i <= 3001; i++) if(!s.count(i)) { cout << i << endl; break; }
}