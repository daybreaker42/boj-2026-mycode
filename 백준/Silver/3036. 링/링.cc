#include <iostream>
#include <vector>
using namespace std;

int gcd(int n, int m);
int main(){
    ios::sync_with_stdio(false);
    int n, dividee, divider, factor;
    int i, j;
    scanf("%d", &n);
    vector<int> radius(n, 0);
    vector<vector<int>> rates(n, vector<int>(2, 0));
    for(i = 0; i < n; i++)
        scanf(" %d", &radius[i]);
    
    rates[0][0] = 1;
    rates[0][1] = 1;
    for(i = 1; i < n; i++){
        dividee = rates[i-1][0];
        divider = rates[i-1][1];
        // 1 : 3 : 5 -> rates[1] = 1 / 3 * 이전, rates[2] = 3 / 5 * 이전횟수
        dividee *= radius[i-1];
        divider *= radius[i];
        // 비율 저장
        factor = gcd(dividee, divider);
        dividee /= factor;
        divider /= factor;
        rates[i][0] = dividee;
        rates[i][1] = divider;
    }
    for(i = 1; i < n; i++)
        printf("%d/%d\n", rates[i][0], rates[i][1]);

    return 0;
}
int gcd(int n, int m){
    if(n % m == 0)
        return m;
    else
        return gcd(m, n % m);
}