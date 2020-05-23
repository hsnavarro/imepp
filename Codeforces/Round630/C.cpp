#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int t;
int n, k;
ll freq[26][N], freq2[26][N];
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < 26; i++) 
      for(int j = 0; j < k; j++) freq[i][j] = 0;

    for(int i = 0; i < s.size(); i++) freq[s[i] - 'a'][i%k]++;

    string ans;
    for(int i = 0; i < k; i++) {
      int mx = -1, id;
      for(int j = 0; j < 26; j++) if(freq[j][i] + freq[j][k-1-i] > mx) mx = freq[j][i] + freq[j][k-1-i], id = j;
      ans += char(id + 'a');
    }

    string aux;
    int cnt = n/k;
    while(cnt--) aux += ans;
    //db(ans);
    //db(aux);

    ll res = 0;
    for(int i = 0; i < s.size(); i++) res += (s[i] != aux[i]);
    cout << res << "\n";
  }
}

