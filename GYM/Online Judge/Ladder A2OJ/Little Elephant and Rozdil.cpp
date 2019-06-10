#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

int n, x, y, aux;
vector<pair<int, int>> pts;
pair<int, int> p, s;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &aux);
        pts.push_back({aux, i});
    }
    sort(pts.begin(), pts.end());
    p = pts[0];
    s = pts[1];

    if(p.first == s.first) printf("Still Rozdil\n");
    else printf("%d\n", p.second);

    return 0;
}