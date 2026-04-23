import sys

def findIdx(n, stIdx, edIdx, lst):
	midIdx = int((stIdx + edIdx) / 2)
	
	if stIdx == edIdx:	# 없어도 그냥 return
		return stIdx
	elif lst[midIdx] < n:
		return findIdx(n, midIdx + 1, edIdx, lst)
	else:
		return findIdx(n, stIdx, midIdx, lst)

while True:
	a, b = map(int, sys.stdin.readline().split())
	if a == 0 and b == 0:
		break

	SIZE = 482
	lst = [0] * SIZE
	lst[0] = 1
	lst[1] = 1

	# lst 피보나치 수로 채우는 부분, O(n)
	for i in range(2, SIZE):
		lst[i] = lst[i - 1] + lst[i - 2]

	# 시작 수와 끝 수의 인덱스를 각각 찾고, 그 차이를 구하는 부분, 이진탐색으로 찾아서 O(log(n))
	stIdx = findIdx(a, 1, SIZE - 1, lst)
	edIdx = findIdx(b, 1, SIZE - 1, lst)

	ans = edIdx - stIdx
	if a <= lst[stIdx] and lst[edIdx] <= b:
		ans += 1
	elif lst[stIdx] < a and b < lst[edIdx]:
		ans -= 1
		
	print(ans)