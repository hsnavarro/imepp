#include <bits/stdc++.h>
using namespace std;

int n, d, r, cnt, a, aux;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> d >> r;
    aux = n;
    while(aux--) cin >> a, cnt += (a <= d);
    cout << (d > r ? n : (cnt+1)/2) << endl;
}