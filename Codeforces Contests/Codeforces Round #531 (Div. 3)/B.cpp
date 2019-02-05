#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5000 + 5;
int freq[N], n, k, a, ok[N][N];
vector<int> v, ans;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a, v.pb(a);
    for(auto x : v) freq[x]++;

    for(int i = 0; i < N; i++) if(freq[i] > k) {cout << "NO" << endl; return 0;}

    cout <<  "YES" << endl;

    int cnt, j = 1;
    for(int i = 0; i < v.size(); i++){
        cnt = 0;
        if(j == k + 1) j = 1;
        while(ok[v[i]][j] != 0){
            j++, cnt++;
            if(cnt == k + 1) {cout << "NO" << endl; return 0;}
            if(j == k + 1) j = 1;
        }
        ans.pb(j); ok[v[i]][j]++, j++;
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;
}