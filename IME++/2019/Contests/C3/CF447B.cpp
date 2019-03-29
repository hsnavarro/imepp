#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

string s;
int w[30], k;
pair<int, int> best = {-1, -INF};

int func(string s){
  int ans = 0;
  for(int i = 0; i < s.size(); i++) ans += w[s[i] - 'a'] * (i + 1);
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  cin >> k;
  for(int i = 0; i < 26; i++) {
    cin >> w[i];
    if(best.second < w[i]){
      best.second = w[i];
      best.first = i;
    }
  }

  for(int i = 0; i < k; i++) s += char(best.first + 'a');
  cout << func(s) << endl;


}
