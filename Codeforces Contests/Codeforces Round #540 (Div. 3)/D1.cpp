#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

const int N = 3e5 + 5;

int n, m;
vector<int> v;

bool test(int k){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += max(0, v[i] - i/k);
    return sum >= m;
}

int bin(int l, int r){
    int mid;
    while(l != r){
        mid = (l+r)/2;
        if(test(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int x = bin(1, 101);
    cout << (x == 101 ? -1 : x) << endl;
}