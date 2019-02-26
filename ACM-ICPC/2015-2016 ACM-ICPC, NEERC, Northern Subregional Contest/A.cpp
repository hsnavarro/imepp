#include<bits/stdc++.h>
using namespace std;

int h, w;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifstream cin("alex.in");
    ofstream cout("alex.out");
    cin >> h >> w;
    if(h > w) swap(h, w);
    cout << fixed << setprecision(15) << max(min(double(w)/3, 1.0*h), min(double(h)/2, double(w)/2)) << endl;
}