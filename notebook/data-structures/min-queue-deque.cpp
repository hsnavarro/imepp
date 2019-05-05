// Min Queue - Operations in O(1)

struct MinQueue {
  int sum = 0, l = 1, r = 0;
  deque<pair<int, int>> d;

  void reset(){
    sum = 0, l = 1, r = 0;
    d.clear();
  }
  
  void push(int x){
    x -= sum;
    while(!d.empty() and d.back().first >= x) d.pop_back();
    d.push_back({x, ++r});
  }

  void add(int x) { sum += x; }
  void pop(){ if(!d.empty() and d.front().second == l++) d.pop_front(); }
  int min() { return d.front().first + sum; }
  int size() { return r - l + 1; }
};
