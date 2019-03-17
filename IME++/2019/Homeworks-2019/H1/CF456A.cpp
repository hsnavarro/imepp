#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 1e6 + 5;

int n, ax, bx;
vector<pii> a, b;

bool cmp(pii a, pii b){
    if(b.nd < a.nd) return false;
    if(b.nd == a.nd and b.st < a.st) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--) cin >> ax >> bx, a.pb({ax, bx});
    b = a;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), cmp);
    for(int i = 0; i < a.size(); i++) 
      if(a[i] != b[i]) return printf("Happy Alex\n"), 0;
    
    printf("Poor Alex\n");
}
