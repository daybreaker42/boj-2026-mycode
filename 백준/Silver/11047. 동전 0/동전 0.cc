// Baekjoon No.
// Time Complexity
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, k, index, cnt;
    int i;
    scanf("%d %d", &n, &k);
    vector<int> coins(n, 0);
    for(i = 0; i < n; i++)
        scanf(" %d", &coins[i]);
    
    // solving
    /*
    1) 작은 수를 2개 이상 사용할 경우, 그 배수가 있다면 배수로 대체할 수 있다.
    2) 대체할 배수가 없는 경우는 그 경우가 최적해인 경우이다.
    */
    cnt = 0;
    index = n - 1;
    while(index >= 0){
        if(k == 0)
            break;
        if(k / coins[index] > 0){
            cnt += k / coins[index];
            k %= coins[index];
        }
        index --;
    }
    printf("%d", cnt);
    return 0;
}