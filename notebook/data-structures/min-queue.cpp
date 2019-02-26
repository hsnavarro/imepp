// Min_Queue
// Operations in O(1)

struct min_queue{
    vector<pii> s1, s2;

    int size(){ return s1.size() + s2.size(); }

    int mini(){
        if(s1.empty() or s2.empty()) return s1.empty() ? s2.back().nd : s1.back().nd;
        return min(s1.back().nd, s2.back().nd);
    }

    void add(int x){
        int mn = s1.empty() ? x : min(s1.back().nd, x);
        s1.pb({x, mn});
    }

    void rem(){
        if(s2.empty()){
            while(s1.size()){
                int x = s1.back().st; s1.pop_back();
                int mn = s2.empty() ? x : min(x, s2.back().nd);
                s2.pb({x, mn});
            }
        }
        s2.pop_back();
    }

};