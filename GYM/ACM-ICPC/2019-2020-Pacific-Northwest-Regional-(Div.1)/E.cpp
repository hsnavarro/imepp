#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

const ll MOD = 11092019;

ll freq[26], mult = 1;
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  for(auto x : s) freq[x - 'a']++;
  for(int i = 0; i < 26; i++) {
    freq[i] = (freq[i] + 1) % MOD;
    mult = (mult*freq[i]) % MOD;
  }
  cout << mult << "\n";
}
