#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
int n, a, freq[10];
vector<tuple<int, int, int>> ans;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--) cin >> a, freq[a]++;
    while(1){
        if(freq[1] and freq[2] and freq[4]) freq[1]--, freq[2]--, freq[4]--, ans.pb({1, 2, 4});
        else if(freq[1] and freq[2] and freq[6]) freq[1]--, freq[2]--, freq[6]--, ans.pb({1, 2, 6});
        else if(freq[1] and freq[3] and freq[6]) freq[1]--, freq[3]--, freq[6]--, ans.pb({1, 3, 6});
        else break;
    }

    for(int i = 0; i < 8; i++) if(freq[i]){ printf("-1\n"); return 0; }
    for(auto x : ans) printf("%d %d %d\n", get<0>(x), get<1>(x), get<2>(x));
}