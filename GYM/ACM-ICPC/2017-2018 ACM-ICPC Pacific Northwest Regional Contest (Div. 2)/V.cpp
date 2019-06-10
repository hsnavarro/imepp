#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

vector<pair<char, ll>> ad, ad_res;
pair<char, ll> aux;
vector<ll> d, d_res;
char esc, a;
ll val, m;

print(){
    for(auto x : ad) printf("%c _ %lld ", x.st, x.nd);
    printf("\n");
    for(auto p : d) printf("%lld ", p);
    printf("\n");
}

void add(char c, ll p){
    for(int i = 0; i < ad.size(); i++) if(ad[i].nd >= p)
            aux = {ad[i].st, ad[i].nd + 1}, swap(ad[i], aux);
    ad.pb({c, p});
}

void del(ll p){
    //if not from original
    for(int i = 0; i < ad.size(); i++) {
        if(ad[i].nd == p){
            swap(ad[i], ad.back());
            ad.pop_back();
            for(int j = 0; j < ad.size(); j++) if(ad[j].nd > p) aux = {ad[j].st, ad[j].nd - 1}, swap(ad[j], aux);
            return;
        }
    }

    // if from original
    ll p_ori = p;
    for(auto x : ad) if(x.nd < p) p_ori--;
    vector<ll> a = d;
    sort(a.begin(), a.end());
    for(auto j : a) if(j <= p_ori) p_ori++;
    d.pb(p_ori);

    for(int j = 0; j < ad.size(); j++) if(ad[j].nd > p) aux = {ad[j].st, ad[j].nd - 1}, swap(ad[j], aux);
}

void input(){
    ad.clear(), d.clear();
    while(scanf(" %c", &esc) and esc != 'E'){
        scanf("%lld", &val);
        if(esc == 'I') scanf(" %c", &a), add(a, val);
        else del(val);
    }

    sort(ad.begin(), ad.end()), sort(d.begin(), d.end());
}

int main(){

    input();
    //print();
    ad_res = ad, d_res = d;
    input();
    //print();

    printf("%d\n", !(ad_res == ad and d_res == d));
}