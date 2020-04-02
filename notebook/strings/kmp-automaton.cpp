// KMP Automaton - <O(26*pattern), O(text)>

// max size pattern
const int N = 1e5 + 5;

int cnt, lps[N], nxt[N+1][26];

void prekmp(string &p) {
  /* If needed lps values 
  for(int i = 1, j = 0; i < p.size(); i++) {
    while(j and p[j] != p[i]) j = lps[j-1];
    if(p[j] == p[i]) j++;
    lps[i] = j;
  }
  */

  nxt[0][p[0] - 'a'] = 1;
  for(int i = 1, j = 0; i <= p.size(); i++) {
    for(int c = 0; c < 26. c++) nxt[i][c] = nxt[j][c];
    if(i == p.size()) continue;
    nxt[i][p[i] - 'a'] = i+1;
    j = nxt[j][p[i] - 'a'];
  }
}

void kmp(string &s, string &p) {
  for(int i = 0, j = 0; i < s.size(); i++) {
    j = nxt[j][s[i] - 'a'];
    if(j == p.size()) cnt++; //match i - j + 1
  }
}
