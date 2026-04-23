#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 10
#define MAX 99999 + 1
using namespace std;


bool isPrime[MAX] = {false};

void initPrimeList();

// 조건1: 서로 다른 두 소수의 합으로 나타낼 수 있는지
bool checkCondition1(int n){
    for(int i = 2; i <= n / 2; i++){
        if(i != n - i && isPrime[i] && isPrime[n - i]) return true;   // i < n / 2 이므로 서로 안겹침
    }
    return false;
}
// 조건2: M으로 나누어 떨어지지 않을때까지 나눈 수가 두 소수의 곱인 경우 (중복 가능)
bool checkCondition2(int n, int divisor){
    while(n % divisor == 0){
        n /= divisor;
    }
    // n 소인수분해
    int cnt = 0;
    // 비트 연산으로 최적화
    while((n & 1) == 0){
        n >>= 1;
        cnt++;
        if(cnt > 2){
            return false;
        }
    }
    
    for(int i = 3; i <= n; i += 2){ // n까지 돌아야
        while(n % i == 0){
            n /= i;
            cnt++;
            if(cnt > 2){
                return false;
            }
        }
    }
    if(cnt == 2) return true;
    return false;
}

int convertNum(vector<int>& arr){
    int result = 0;
    for(int num : arr){
        result = result * 10 + num;
    }
    return result;
}

int power(int n, int k){
    int result = 1;
    for(int i = 0; i < k; i++){
        result *= n;
    }
    return result;
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int length, divisor;
    cin >> length >> divisor;

    initPrimeList();

    // solving
    int count = 0, num = 0;
    vector<bool> selected(SIZE, false);
    fill(selected.end() - length, selected.end(), true);
    
    do{
        vector<int> temp;
        for(int i = 0; i < SIZE; i++){
            if(selected[i]) temp.push_back(i);
        }
        do{
            if(temp[0] == 0) continue;

            int target = convertNum(temp);
            if(checkCondition1(target) && checkCondition2(target, divisor)){
                count++;
            }

        }while(next_permutation(temp.begin(), temp.end()));
    }while(next_permutation(selected.begin(), selected.end()));

    cout << count;
    
	return 0;
}

void initPrimeList(){
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i <= MAX; i++){
        if(isPrime[i]){
            for(int j = i * 2; j <= MAX; j += i){
                isPrime[j] = false;
            }
        }
    }
}