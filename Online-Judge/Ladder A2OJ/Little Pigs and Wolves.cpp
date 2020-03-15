#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 11;

int n, m, cnt;
char table[N][N];
string s;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void go(int i, int j){
    for(int k = 0; k < 4; k++)
        if (i + dx[k] >= 0 and i + dx[k] < n and j + dy[k] >= 0 and j + dy[k] < m)
            if (table[i + dx[k]][j + dy[k]] == 'P') { table[i + dx[k]][j + dy[k]] = '.', cnt++; return;}
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++) table[i][j] = s[j];
    }

    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (table[i][j] == 'W') go(i, j);

    cout << cnt << endl;

}