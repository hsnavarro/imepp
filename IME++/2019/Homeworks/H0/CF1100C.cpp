#include <bits/stdc++.h>
using namespace std;

const long double PI = acos(-1.);

int n, r;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> r;
    cout << fixed << setprecision(12) << r*sin(PI/n)/(1 - sin(PI/n)) << endl;
}