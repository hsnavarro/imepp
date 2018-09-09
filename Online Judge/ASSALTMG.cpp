//
// Created by Henrique Navarro on 30/08/2018.
//

for(int i = 1; i < (1<<n); i++){
ans = 0;
for(int j = 0; j < 20; j++){
if(i & (1<<j)){
ans = ans | chaves[j];
}
}