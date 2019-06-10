#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

int n, res = 1;
double x1, x2, k, b;
vector<pair<double, double>> v1, v2;

bool cmp(pair<double, double> a, pair<double, double> b){
    if(b.nd < a.nd) return false;
    if(b.nd == a.nd and b.st < a.st) return false;
    return true;
}

int main(){
    cin >> n;
    cin >> x1 >> x2;
    while(n--){
        cin >> k >> b;
        v1.pb({k*x1 + b, k*x2 + b});
    }
    v2 = v1;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), cmp);

    for(int i = 0; i < v1.size(); i++) if(v1[i] != v2[i]) { res = 0; break;}

    cout << (!res ? "YES" : "NO") << endl;

}