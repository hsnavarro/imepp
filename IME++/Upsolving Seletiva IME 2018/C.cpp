#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define st first
#define nd second
using namespace std;

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

int n;
int res[7][7], col[7], lin[7], sreg[37], reg[7][7];
int val_sreg_cont[37], val_sreg_size_cont[37];
int val_sreg[37], val_sreg_size[37], idx_reg[7][7];

bool check(int x, int y, int k){
    if((col[y] | lin[x] | sreg[idx_reg[x][y]] | reg[(x-1)/2 + 1][(y-1)/3 + 1]) & (1<<k)) return false;
    if(val_sreg_size_cont[idx_reg[x][y]] == val_sreg_size[idx_reg[x][y]] - 1 and
       val_sreg_cont[idx_reg[x][y]] + k != val_sreg[idx_reg[x][y]]) return false;
    return true;
}

void add(int x, int y, int k){
    res[x][y] = k;
    col[y] += (1<<k);
    lin[x] += (1<<k);
    sreg[idx_reg[x][y]] += (1<<k);
    reg[(x-1)/2 + 1][(y-1)/3 + 1] += (1<<k);
    val_sreg_cont[idx_reg[x][y]] += k;
    val_sreg_size_cont[idx_reg[x][y]]++;
}

void rem(int x, int y, int k){
    res[x][y] = 0;
    col[y] -= (1<<k);
    lin[x] -= (1<<k);
    sreg[idx_reg[x][y]] -= (1<<k);
    reg[(x-1)/2 + 1][(y-1)/3 + 1] -= (1<<k);
    val_sreg_cont[idx_reg[x][y]] -= k;
    val_sreg_size_cont[idx_reg[x][y]]--;
}

bool bt(int x, int y){
    if(y > 6) return true;
    if(x > 6) return bt(1, y + 1);

    for(int k = 1; k <= 6; k++){
        if(check(x, y, k)){
            add(x, y, k);
            if(bt(x+1,y)) return true;
            rem(x, y, k);
        }
    }
    return false;
}


int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &val_sreg[i]);

    for(int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            scanf("%d", &idx_reg[i][j]);
            val_sreg_size[idx_reg[i][j]]++;
        }
    }

    bt(1,1);

    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            printf("%d%s", res[i][j], j == 6 ? "\n" : " ");
        }
    }

    return 0;
}