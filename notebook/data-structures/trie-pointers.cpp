// Trie - Using pointers

class Node{
  public:
  bool isEnd;
  Node* f[26];
  Node(){
    isEnd = false;
    for(int i = 0; i < 26; i++) f[i] = nullptr;
  }
};

class Trie{
  public:
  Node* root = new Node();

  Node* insert(char input, Node* lastNode){
    int index = input - 'a';
    if(lastNode -> f[index] != nullptr) return lastNode -> f[index];
    Node* answer = new Node();
    lastNode -> f[index] = answer;
    return answer;
  }

  void addString(string s){
    Node* result = root;
    for(auto c : s) result = insert(c, result);
    result -> isEnd = true;
  }

  bool Search(string s){
    Node* result = root;
    for(auto c : s){
      if(result -> f[c-'a'] == nullptr) return false;
      result = result -> f[c-'a'];
      if(c == s.back()) return result -> isEnd;
    }
  }

  void print(){
    queue<pair<Node*, int>> q;
    int h = 1;
    q.push({root, 1});
    while(!q.empty()){
      Node* u = q.front().first;
      if(q.front().second != h) cout << endl, h = q.front().second;
      q.pop();
      for(int i = 0; i < 26; i++)
        if(u -> f[i] != nullptr) 
          cout << char(i + 'a') << " ", q.push({u -> f[i], h+1});
    }
  }
};

