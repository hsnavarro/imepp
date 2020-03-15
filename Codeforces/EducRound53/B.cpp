#include<bits/stdc++.h>
using namespace std;

deque<int> s;
set<int> c;
vector<int> ans;
int n, aux, cont, k;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &aux);
        c.insert(aux);
        s.push_back(aux);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        cont = 0;
        if(c.count(aux)){
            while(s.front() != aux and s.size()){
                //cout << s.front() << endl;
                cont++;
                if(!c.empty()) c.erase(s.front());
                if(s.size()) s.pop_front();
            }
            s.pop_front();
            cont++;
        }
        ans.push_back(cont);
    }

    for(int i = 0; i < ans.size(); i++) printf("%d%s", ans[i], i == ans.size()-1 ? "\n" : " ");




    return 0;
}