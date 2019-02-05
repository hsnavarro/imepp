#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

map<ll, char> ad, ad_res;
vector<ll> d, d_res;
char esc, a;
ll val, m;

void add(char c, ll p){
    map<ll, char> aux;
    aux[p] = c;
    for(auto x : ad) aux[x.st + (x.st >= p)] = x.nd;
    ad = aux;
}

void del(ll p){
    if(ad.count(p)) ad.erase(p);
    else{
        ll p_ori = p;
        for(auto x : ad) if(x.st < p) p_ori--;
        vector<ll> a = d;
        sort(a.begin(), a.end());
        for(auto j : a) if(j <= p_ori) p_ori++;
        d.pb(p_ori);
    }
    map<ll, char> aux;
    for(auto x : ad) aux[x.st - (x.st > p)] = x.nd;
    ad = aux;
}

void input(){
    ad.clear(), d.clear();
    while(scanf(" %c", &esc) and esc != 'E'){
        scanf("%lld", &val);
        if(esc == 'I') scanf(" %c", &a), add(a, val);
        else del(val);
    }
    sort(d.begin(), d.end());
}

int main(){

    input();
    ad_res = ad, d_res = d;
    input();

    printf("%d\n", !(ad_res == ad and d_res == d));
}