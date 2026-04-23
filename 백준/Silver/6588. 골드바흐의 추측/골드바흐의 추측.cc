/** 
DATE : 230406
#소수판정, 골드바흐의 추측
*/

#include <bits/stdc++.h>
#define SIZE 1000001
using namespace std;

int primeArr[SIZE];
int primeIdxSearch(int p, int st, int ed, int cond);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	// 소수 전처리
	bool isPrime[SIZE];
	int primeIdx = 0;
	memset(isPrime, true, sizeof(isPrime));
	
	for(int i = 2; i < SIZE; i++){
		if(isPrime[i]){
			for(int j = i * 2; j < SIZE; j += i){
				isPrime[j] = 0;
			}
			primeArr[primeIdx++] = i;	// primeArr -> 백만 이하 소수만 있는 배열
		}
	}
	
	int n;
	while(1){
		cin >> n;
		if(!n) break;
		
		// solving
		int i = 0, j = primeIdx - 1;
		while(i <= j && i >= 0 && j < primeIdx){	// primeIdx는 결국 소수의 개수가 됨.
			if(primeArr[i] + primeArr[j] == n){
				cout << n << " = " << primeArr[i] << " + " << primeArr[j] << "\n";
				break;
			}else if(primeArr[i] + primeArr[j] < n){
				int target = n - primeArr[j];
				i = primeIdxSearch(target, i + 1, j, 2);	// i 증가
				}else {
				int target = n - primeArr[i];
				j = primeIdxSearch(target, i, j - 1, 1);	// j 감수
			}
		}
	}
  return 0;
}

// p를 받아 p와 가장 가까운 소수를 반환하는 함수
// cond 1 -> 작은거, 2 -> 큰거 반환함
int primeIdxSearch(int p, int st, int ed, int cond){
	if(st == ed) return st;
	int mid = (st + ed) / 2;
	if(primeArr[mid] == p) return mid;
	else if(primeArr[mid] > p){
		return primeIdxSearch(p, st, mid, cond);
	}else{
		if(cond == 1 && primeArr[mid + 1] > p) return mid;
		return primeIdxSearch(p, mid + 1, ed, cond);
	}
}