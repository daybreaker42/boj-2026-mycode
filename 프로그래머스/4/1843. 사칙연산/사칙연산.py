def solution(arr):
    # 1. 입력 배열 파싱: 숫자와 연산자 분리
    nums = [int(x) for i, x in enumerate(arr) if i % 2 == 0]
    ops = [x for i, x in enumerate(arr) if i % 2 != 0]
    
    n = len(nums)
    
    # 2. DP 테이블 초기화
    # 무한대 값 설정을 위해 10^9 사용 (문제 조건 상 내부 최대/최소 범위 안쪽 안전지대)
    INF = float('inf')
    max_dp = [[-INF] * n for _ in range(n)]
    min_dp = [[INF] * n for _ in range(n)]
    
    # 기저 조건 설정: 길이 1인 구간 (자기 자신 숫자)
    for i in range(n):
        max_dp[i][i] = nums[i]
        min_dp[i][i] = nums[i]
        
    # 3. DP Bottom-Up 바깥쪽 루프: 구간의 길이(step)를 1부터 n-1까지 확장
    for step in range(1, n):
        for i in range(n - step):
            j = i + step
            
            # i부터 j까지의 구간 안에서 최댓값과 최솟값을 갱신하기 위한 임시 변수
            local_max = -INF
            local_min = INF
            
            # k는 i와 j 사이에서 수식을 쪼갤 연산자의 인덱스
            for k in range(i, j):
                if ops[k] == '+':
                    # 덧셈인 경우: Max + Max, Min + Min
                    temp_max = max_dp[i][k] + max_dp[k+1][j]
                    temp_min = min_dp[i][k] + min_dp[k+1][j]
                else:
                    # 뺄셈인 경우: Max - Min, Min - Max
                    temp_max = max_dp[i][k] - min_dp[k+1][j]
                    temp_min = min_dp[i][k] - max_dp[k+1][j]
                
                if temp_max > local_max:
                    local_max = temp_max
                if temp_min < local_min:
                    local_min = temp_min
            
            max_dp[i][j] = local_max
            min_dp[i][j] = local_min

    # 전체 구간 nums[0]부터 nums[n-1]까지의 최댓값 반환
    return max_dp[0][n-1]