#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

int n, m, t[105][105], c[4], res;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool check(int i, int j){
    return i < n and i >= 0 and j < m and j >= 0;
}

void go(int i, int j){
    for(int l = 0; l < 4; l++) c[l] = 1;
    for(int p = 0; p < 4; p++){
        for(int k = 1; k < 100; k++){
            if(check(i + k*dx[p], j + k*dy[p]) and t[i + k*dx[p]][j + k*dy[p]] >= t[i][j]) c[p] = 0;
        }
    }
    res += c[0] + c[1] + c[2] + c[3];
}

int main(){
    ifstream cin("lucky.in");
    ofstream cout("lucky.out");
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> t[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) go(i, j);
    cout << res << endl;
}