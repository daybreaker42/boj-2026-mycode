/** 
* DATE : 230409
* #Two Pointer
*/
#include <bits/stdc++.h>
#define MAX 4000001
using namespace std;

bool isPrime[MAX] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> primes;
	
	// 에라토스테네스 전처리
	for(int i = 2; i <= n; i++){
		if(!isPrime[i]){
			primes.push_back(i);
			for(int j = 2; i * j <= n; j++){
				isPrime[i * j] = 1;
			}
		}
	}
	
	int totalSum = 0, e = 0, ans = 0;
	for(int s = 0; s < primes.size(); s++){
		while(totalSum < n && e < primes.size()){
			totalSum += primes[e++];
		}
		if(totalSum == n) ans++;
		totalSum -= primes[s];
	}
	
	cout << ans;
	
	return 0;
}