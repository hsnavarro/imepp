#include <bits/stdc++.h>
using namespace std;

int n, x;
int pos[] = {0, 1, 2};

int main(){
  cin >> n >> x;
  n %= 6;

  for(int i = 1; i <= n; i++) 
    (i & 1) ? swap(pos[0], pos[1]) : swap(pos[1], pos[2]);
  
  cout << pos[x] << endl;
}
