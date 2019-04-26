#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

string a, b;
int posa, nega, posb, negb, in, fat[N];
double ans;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  cout << setprecision(12) << fixed;
  for(auto x : a) x == '+' ? posa++ : nega++;
  for(auto x : b) posb += (x == '+'), negb += (x == '-');
  in = b.size() - (posb + negb);
  fat[0] = 1;
  for(int i = 1; i <= in; i++) fat[i] = i*fat[i-1];
  posa -= posb;
  nega -= negb;
  if(posa < 0 or nega < 0 or posa + nega != in) return cout << ans << endl, 0;
  cout << fat[in]/(fat[posa]*fat[in - posa]) * pow(0.5, in) << endl;
}
