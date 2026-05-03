answer = 0
dungeons_info = []
def get_order(k, order_lst, length):
    global answer, dungeons_info
    if len(order_lst) == length:
        left_k = k
        cnt = 0
        for idx in order_lst:
            if left_k >= dungeons_info[idx][0]:
                left_k -= dungeons_info[idx][1]
                cnt += 1
        answer = max(answer, cnt)
        
    for i in range(length):
        if i not in order_lst:
            get_order(k, order_lst + [i], length)
    return
def solution(k, dungeons):
    global answer, dungeons_info
    is_visited = [False] * len(dungeons)
    dungeons_info = [dungeon + [index] for index, dungeon in enumerate(dungeons)]
    
    get_order(k, [], len(dungeons))

    return answer