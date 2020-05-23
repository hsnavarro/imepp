#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int n, k, cnt_ans[N], cnt[N], in[N];
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> in[i];
  for(int i = 1; i <= n; i++) cnt[in[i]] = max(cnt[in[i]], i);

  for(int i = 1; i <= n; i++) {
    if(cnt_ans[in[i]]) continue;
    while(ans.size() and ans.back() > in[i] and cnt[ans.back()] > i) {
      cnt_ans[ans.back()]--, ans.pop_back();
    }
    ans.push_back(in[i]);
    cnt_ans[in[i]]++;
  }
  for(int i = 0; i < k; i++)  cout << ans[i] << " \n"[i == k-1];
}
