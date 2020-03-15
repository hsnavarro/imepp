#include <bits/stdc++.h>
using namespace std;

string s1, s2, ans;
int freq1[30], freq2[30];
// different characters -> NO
// two characters equal -> YES
// all characters unique -> same parity
int t, n, cond, inv, inv1, inv2;

void mergesort(int l, int r, string &s){
  if(l == r) return;
  int mid = (l+r)/2;
  mergesort(l, mid, s);
  mergesort(mid+1, r, s);
  int i = l, j = mid+1, k = l;
  while(i <= mid or j <= r){
    if(i <= mid and (j > r or s[i] <= s[j])) ans[k++] = s[i++];
    else ans[k++] = s[j++], inv += j-k;
  }
  for(int i = l; i <= r; i++) s[i] = ans[i];
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n >> s1 >> s2;
    for(int i = 0; i < 30; i++) freq1[i] = 0, freq2[i] = 0;
    for(auto x : s1) freq1[x - 'a']++;
    for(auto x : s2) freq2[x - 'a']++;
    
    cond = 1;
    for(int i = 0; i < 30; i++) if(freq1[i] != freq2[i]) cond = 0;
    if(!cond) { cout << "NO\n"; continue; }
    cond = 0;
    for(int i = 0; i < 30; i++) if(freq1[i] >= 2) cond = 1;
    if(cond) { cout << "YES\n"; continue; }
      
    //cerr << "chegou aqui" << endl;

    inv = 0;
    mergesort(0, s1.size()-1, s1);
    inv1 = inv, inv = 0;
    mergesort(0, s2.size()-1, s2);
    inv2 = inv;
    //cerr << "inv1, inv2: " << inv1 << " " << inv2 << endl;
    if(inv1 < inv2) swap(inv1, inv2);
    cout << (((inv1 - inv2) & 1) ? "NO\n" : "YES\n");
  }
}
