// Min Heap
// Operation in O(log n)

mt19937_64 llrand(random_device{}());

struct node{
    int val;
    node *l, *r;
    node(int x) : val(x), l(0), r(0) {}
};

struct min_heap{
    node *merge(node *t1, node *t2){
        if(!t1 and !t2) return nullptr;
        if(!t1 or !t2) return t1 ? t1 : t2;
        if(t2->val < t1->val) swap(t1, t2);
        if(llrand() & 1ll) t1->l = merge(t1->l, t2);
        else t1->r = merge(t2, t1->r);
        return t1;
    }
};