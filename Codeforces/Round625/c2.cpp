#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const char rm='a'-1;
const char bar='a'-2;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  cin >> n;
  cin >> s;

  int ans=0;

  for(char c='z'; c>'a'; c--){
    for(int k=0; k<n; k++){
      for(int i=0; i<n; i++){
        if(s[i]!=c) continue;
        int l=i-1, r=i+1;
        while(l>=0 && s[l]==rm) l--;
        while(r<n && s[r]==rm) r++;
        if((l>=0 && s[l]==c-1) || (r<n && s[r]==c-1)) ans++, s[i]=rm;
      }
    }
  }

  cout << ans << endl;
}
